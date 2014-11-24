VERSION = 3.02
CXX     = /usr/bin/g++
CFLAGS  = -Wall -g

OBJ	= main.o src/Human.o

Human.o : src/Human.cpp
	$(CXX) $(CFLAGS) -c src/Human.cpp

main.o : main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

main:	$(OBJ)
	$(CXX) $(CFLAGS) -o main $(OBJ)

clean:
	rm *.o main
