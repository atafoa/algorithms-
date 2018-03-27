CC = gcc
FLAGS = 

all: executable
	./a.out

executable: lab4.o 
	${CC} ${FLAGS} lab4.o 

lab4.o: lab4.c
	${CC} ${FLAGS} -c lab4.c -o lab4.o

clean:
	rm -rf a.out *.o lab4 

