FLAGS = -g
#FLAGS = -O2

all: test_Queue test_State test_Jug test_ABC 

test_Queue: State.o Queue.o test_Queue.cpp
	g++ ${FLAGS} State.o Queue.o test_Queue.cpp -o test_Queue

test_State: State.o test_State.cpp
	g++ ${FLAGS} State.o test_State.cpp -o test_State

test_Jug: State.o Queue.o Jug.o test_Jug.cpp
	g++ ${FLAGS} State.o Queue.o Jug.o test_Jug.cpp -o test_Jug

test_ABC: A.o B.o C.o test_ABC.cpp
	g++ ${FLAGS} A.o B.o C.o test_ABC.cpp -o test_ABC

A.o: A.h A.cpp
	g++ ${FLAGS} -c A.cpp

B.o: B.h B.cpp
	g++ ${FLAGS} -c B.cpp

C.o: C.h C.cpp
	g++ ${FLAGS} -c C.cpp

State.o: State.h State.cpp
	g++ ${FLAGS} -c State.cpp

Queue.o: Queue.h Queue.cpp
	g++ ${FLAGS} -c Queue.cpp

Jug.o: Jug.h Jug.cpp
	g++ ${FLAGS} -c Jug.cpp

clean:
	rm -f *.o test_Queue test_State test_Jug test_ABC


