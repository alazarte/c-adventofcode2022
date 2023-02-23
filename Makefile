cflags=-Wall -Wextra
day=4

.PHONY: build solve.o
all: build

build: solve.o
	cc ${cflags} solve.o main.c

solve.o:
	cc ${cflags} -c day${day}/solve.c
