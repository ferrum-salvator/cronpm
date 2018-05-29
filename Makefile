cc=clang
CFLAGS=-g

main: main.o parse.o status.o
	$(CC) -o main main.o parse.o status.o
