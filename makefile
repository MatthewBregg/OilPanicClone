
#Compiler
CC = g++
#Cflags
CFLAGS =  -Wall -std=c++0x 
#Libraries
LIB =  -lsfml-window -lsfml-system -lsfml-graphics
all: main


main: main.o drops.o
	$(CC) $(CFLAGS) main.o drops.o -o main $(LIB)

drops.o : drops.cpp drops.hpp
	$(CC) $(CFLAGS) -c drops.cpp
main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp $(LIB)  


clean: *.o
	rm *.o
