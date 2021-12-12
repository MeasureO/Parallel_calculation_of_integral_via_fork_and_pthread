#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "integral.h"

static double a = 0.;
static double b = 1.;
static int n = 100000000;

static double total = 0.;

static pthread_mutex_t total_mutex = PTHREAD_MUTEX_INITIALIZER;

static int p;

void *process_function(void *pa)
{
    int my_rank = (int)pa;
    double len = (b - a) / p;
    int local_n = n / p;
    double local_a = a + my_rank * len;
    double local_b = local_a + len;
    double integral;

    integral = integrate(local_a, local_b, local_n);

    pthread_mutex_lock(&total_mutex);
    total += integral;
    pthread_mutex_unlock(&total_mutex);

    return 0;
}

int main(int argc, char *argv[])
{
    pthread_t *threads;
    int i;

    if (argc != 2)
    {
        printf("Usage: %s <instances>\n", argv[0]);
        return 1;
    }

    p = (int)strtol(argv[1], 0, 10);
    if (!(threads = (pthread_t *)malloc(p * sizeof(pthread_t))))
    {
        fprintf(stderr, "Not enought memory!\n");
        return 1;
    }

    for (i = 0; i < p; i++)
    {
        if (pthread_create(threads + i, 0, process_function, (void *)i))
        {
            fprintf(stderr, "Cannot create thread #%d!\n", i);
            return 2;
        }
    }

    for (i = 0; i < p; i++)
    {
        if (pthread_join(threads[i], 0))
        {
            fprintf(stderr, "Cannot wait thread #%d!\n", i);
        }
    }

    free(threads);

    printf("Integral from %lf to %lf = %.18lf\n", a, b, total);

    return 0;
}