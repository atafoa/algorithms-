CC = gcc


a: RB.o lab5driver.o 
	${CC} ${FLAGS} RB.o lab5driver.o 
	./a.out < lab5.a.dat.txt

b: RB.o lab5driver.o 
	${CC} ${FLAGS} RB.o lab5driver.o 
	./a.out < lab5.b.dat.txt

c: RB.o lab5driver.o 
	${CC} ${FLAGS} RB.o lab5driver.o 
	./a.out < lab5.c.dat.txt

d: RB.o lab5driver.o 
	${CC} ${FLAGS} RB.o lab5driver.o 
	./a.out < lab5.d.dat.txt


RB.o: RB.c
	${CC} ${FLAGS} -c RB.c -o RB.o

lab5driver.o: lab5driver.c
	${CC} ${FLAGS} -c lab5driver.c -o lab5driver.o

clean:
	rm -rf a.out *.o RB lab5driver 

