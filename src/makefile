all: list
	
list: list.o
	@echo "compiling list"
	@gcc -o list list.o -Wall
list.o: list.c
	@gcc -c list.c -o list.o -Wall

clean:
	@rm -f *.exe *.o *.out 
