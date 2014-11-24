VERSION = 3.02
CXX     = /usr/bin/g++
CFLAGS  = -Wall -g

OBJ	= main.o Human.cpp

Human.o : src/Human.cpp
	$(CXX) $(CFLAGS) -c src/Human.cpp

main.o : main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

main:	$(OBJ)
	$(CXX) $(CFLAGS) -o main $(OBJ)

clean:
	rm *.o main
