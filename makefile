# $@ target
# $^ sources

bin = ./bin
src = ./src
errFlags = -Wall -Wextra -Wpedantic -Werror 
opt = -O3
#
all: libs
	
libs: list dict
	@echo "Compiling dll file"
	gcc -shared -o $(bin)/cmm.dll $(bin)/list.o $(bin)/dict.o

list: $(src)/list.c
	gcc -c $^ -o $(bin)/$@.o $(errFlags) $(opt)

dict: $(src)/dict.c
	gcc -c $^ -o $(bin)/$@.o $(errFlags) $(opt)

clean:
	rm -f $(bin)/*.dll $(bin)/*.o
