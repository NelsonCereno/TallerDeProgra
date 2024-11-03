FLAGS = -g
#FLAGS = -O2

all: main

main: State.o Queue.o Jug.o utils.o HashTable.o main.cpp
	g++ ${FLAGS} State.o Queue.o Jug.o utils.o HashTable.o main.cpp -o main

State.o: State.h State.cpp
	g++ ${FLAGS} -c State.cpp

Queue.o: Queue.h Queue.cpp
	g++ ${FLAGS} -c Queue.cpp

Jug.o: Jug.h Jug.cpp
	g++ ${FLAGS} -c Jug.cpp

utils.o: utils.h utils.cpp
	g++ ${FLAGS} -c utils.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ ${FLAGS} -c HashTable.cpp

clean:
	rm -f *.o main