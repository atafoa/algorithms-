CC = gcc
FLAGS = 

all: executable

a: lab6.o 
	${CC} ${FLAGS} lab6.o 
	./a.out < lab6spr18.a.dat.txt
	
b: lab6.o
	${CC} ${FLAGS} lab6.o 
	./a.out < lab6spr18.b.dat.txt

c: lab6.o
	${CC} ${FLAGS} lab6.o 
	./a.out < lab6spr18.c.dat.txt

d: lab6.o
	${CC} ${FLAGS} lab6.o 
	./a.out < lab6spr18.d.dat.txt

lab6.o: lab6.c
	${CC} ${FLAGS} -c lab6.c -o lab6.o

clean:
	rm -rf a.out *.o lab6 

