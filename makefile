# $@ target
# $^ sources

bin = ./bin
src = ./src
errFlags = -Wall -Wextra -Wpedantic -Werror 
opt = -O3
#
all: libs exec
	
libs: list dict
	gcc -shared -o $(bin)/cmm.dll $(bin)/list.o $(bin)/dict.o

exec: $(src)/exec.c
	gcc -o $(bin)/$@.exe $^ $(opt) $(errFlags) -L$(bin) -lcmm

list: $(src)/list.c
	gcc -c $^ -o $(bin)/$@.o $(errFlags) $(opt)

dict: $(src)/dict.c
	gcc -c $^ -o $(bin)/$@.o $(errFlags) $(opt)

clean:
	rm -f $(bin)/*.dll $(bin)/*.o $(bin)/*.exe
