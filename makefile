CC = g++
CFLAGS = -g -Wall -std=c++11

default: lab4

lab4: Pathfinder.o main.o
	$(CC) $(CFLAGS) -o lab4 Pathfinder.o main.o

Pathfinder.o: Pathfinder.cpp Pathfinder.h PathfinderInterface.h 
	$(CC) $(CFLAGS) -c Pathfinder.cpp

main.o: main.cpp Pathfinder.h 
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) lab4 *.o *.~
