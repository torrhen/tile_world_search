# compiler to use
CXX = g++
# include compiler flags for all warnings and debugging
# add /lib folder containing header files
INC_DIR = ../include/
CXXFLAGS = -c -Wall -I$(INC_DIR)

# to run from src/ 
# ming32-make         (to complie)
# ming32-make run     (to execute program)
# ming32-make clean   (to delete files)

# add Node
program: main.o Node.o Grid.o
	$(CXX) Grid.o Node.o main.o -o program

main.o: main.cpp
	$(CXX) -c main.cpp

Node.o: Node.cpp $(INC_DIR)Node.h
	$(CXX) -c Node.cpp

Grid.o: Grid.cpp $(INC_DIR)Grid.h
	$(CXX) -c Grid.cpp

run:
	program.exe

clean: 
	del *.o program.exe
