# compiler to use
CXX = x86_64-w64-mingw32-g++

# include compiler flags for all warnings and debugging
# add /lib folder containing header files
INC_DIR = ../include/
CXXFLAGS = -c -Wall -I$(INC_DIR)

# to run from src/ 
# mingw32-make         (to complie)
# mingw32-make run     (to execute program)
# mingw32-make clean   (to delete files)

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
