
#Compiler
CC = g++
#Cflags
CFLAGS =  -Wall 
#Libraries
LIB =  -lsfml-window -lsfml-system -lsfml-graphics
all: main


main: main.o drops.o bucket.o
	$(CC) $(CFLAGS) main.o drops.o bucket.o -o main $(LIB)

drops.o : drops.cpp drops.hpp
	$(CC) $(CFLAGS) -c drops.cpp

bucket.o : bucket.cpp bucket.hpp
	$(CC) $(CFLAGS) -c bucket.cpp
main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp $(LIB)  


clean: *.o
	rm *.o
