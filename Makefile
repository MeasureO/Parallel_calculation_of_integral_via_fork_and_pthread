all: 
	@echo  "\e[1;31m ВЫЧИСЛЕНИЕ ИНТЕГРАЛА БЕЗ РАСПАРАЛЛЕЛИВАНИЯ\e[0m"
	gcc sequential.c integral.c -o sequential.out
	./sequential.out
	@echo  "\e[1;31m ВЫЧИСЛЕНИЕ ИНТЕГРАЛА ПРИ РАСПАРАЛЛЕЛИВАНИИ С ПОМОЩЬЮ fork от 1 до 8 процессов\e[0m"
	gcc process.c integral.c -o process.out
	./process.out 1
	./process.out 2
	./process.out 3
	./process.out 4
	./process.out 5
	./process.out 6
	./process.out 7
	./process.out 8
	@echo  "\e[1;31m ВЫЧИСЛЕНИЕ ИНТЕГРАЛА ПРИ РАСПАРАЛЛЕЛИВАНИИ С ПОМОЩЬЮ pthread от 1 до 8 процессов\e[0m"
	gcc thread.c integral.c -o thread.out
	./thread.out 1
	./thread.out 2
	./thread.out 3
	./thread.out 4
	./thread.out 5
	./thread.out 6
	./thread.out 7
	./thread.out 8
	rm *.out