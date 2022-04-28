all: list
	
list: list.o
	@echo "compiling list"
	@gcc -o list list.o
list.o: list.c
	@gcc -c list.c -o list.o

clean:
	@rm -f *.exe *.o *.out 
