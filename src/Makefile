# compiler to use
CXX = g++
# include compiler flags for all warnings and debugging
# add /lib folder containing header files
HEADER_DIR = ../lib/
CXXFLAGS = -c -Wall -I$(HEADER_DIR)

output: main.o Board.o
	$(CXX) Board.o main.o -o output

main.o: main.cpp
	$(CXX) -c main.cpp

Board.o: Board.cpp $(HEADER_DIR)Board.h
	$(CXX) -c Board.cpp

run:
	output.exe

clean: 
	del *.o *.h.gch output.exe
