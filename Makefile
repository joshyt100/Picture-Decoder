decoder: main.o stack.o
	gcc -o decoder main.o stack.o

main.o: main.c
	gcc -c -Wall main.c

stack.o: stack.c stack.h
	gcc -c -Wall stack.c
