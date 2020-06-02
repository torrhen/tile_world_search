# compiler to use
CXX = g++
# include compiler flags for all warnings and debugging
# add /lib folder containing header files
HEADER_DIR = ../lib/
CXXFLAGS = -c -Wall -I$(HEADER_DIR)

# to run from src/ 
# ming32-make         (to complie)
# ming32-make run     (to execute program)
# ming32-make clean   (to delete files)

program: main.o Board.o
	$(CXX) Board.o main.o -o program

main.o: main.cpp
	$(CXX) -c main.cpp

Board.o: Board.cpp $(HEADER_DIR)Board.h
	$(CXX) -c Board.cpp

run:
	program.exe

clean: 
	del *.o *.h.gch program.exe
