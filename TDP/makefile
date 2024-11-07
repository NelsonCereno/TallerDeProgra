FLAGS = -g
#FLAGS = -O2

all: main test_HashTable test_Jug test_Queue test_State test_Utils

main: State.o Queue.o Jug.o HashTable.o Utils.o main.cpp
	g++ ${FLAGS} State.o Queue.o Jug.o HashTable.o Utils.o main.cpp -o main

test_HashTable: State.o HashTable.o Utils.o test_HashTable.cpp
	g++ ${FLAGS} State.o HashTable.o Utils.o test_HashTable.cpp -o test_HashTable

test_Jug: State.o Queue.o HashTable.o Jug.o Utils.o test_Jug.cpp
	g++ ${FLAGS} State.o Queue.o HashTable.o Jug.o Utils.o test_Jug.cpp -o test_Jug

test_Queue: State.o Queue.o Utils.o test_Queue.cpp
	g++ ${FLAGS} State.o Queue.o Utils.o test_Queue.cpp -o test_Queue

test_State: State.o Utils.o test_State.cpp
	g++ ${FLAGS} State.o Utils.o test_State.cpp -o test_State

test_Utils: Utils.o test_Utils.cpp
	g++ ${FLAGS} Utils.o test_Utils.cpp -o test_Utils

State.o: State.h State.cpp
	g++ ${FLAGS} -c State.cpp

Queue.o: Queue.h Queue.cpp
	g++ ${FLAGS} -c Queue.cpp

Jug.o: Jug.h Jug.cpp
	g++ ${FLAGS} -c Jug.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ ${FLAGS} -c HashTable.cpp

Utils.o: Utils.h Utils.cpp
	g++ ${FLAGS} -c Utils.cpp

clean:
	rm -f *.o main test_HashTable test_Jug test_Queue test_State test_Utils