CC = gcc
FLAGS = 

all: executable

executable: RB.o lab5driver.o 
	${CC} ${FLAGS} RB.o lab5driver.o 

RB.o: RB.c
	${CC} ${FLAGS} -c RB.c -o RB.o

lab5driver.o: lab5driver.c
	${CC} ${FLAGS} -c lab5driver.c -o lab5driver.o

clean:
	rm -rf a.out *.o RB lab5driver 

