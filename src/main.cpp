#include "../lib/Board.h"
#include "../lib/Node.h"

#include <iostream>

int main()
{
	Board StartBoard;

	StartBoard.show();

	Node RootNode(StartBoard);

	RootNode.getState().show();

	return 0;
}