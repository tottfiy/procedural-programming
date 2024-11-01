my_program: main.o	list.o	c_list.h
    gcc -o list main.o list.o

main.o: main.c	c_list.h
    gcc -c main.c

list.o: c_list.c	c_list.h
    gcc -c c_list.c

