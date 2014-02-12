all: proc1

p1: proc1.c
	gcc -o proc1 proc1.c

remove:
	rm -rf proc1
	rm -rf bin

install:
	mkdir bin
	mv proc1 bin