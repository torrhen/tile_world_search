#include "../lib/Board.h"
#include "../lib/Node.h"

#include <iostream>

int main()
{
	Board StartBoard;

	Node RootNode(StartBoard);

	Node NewNode(RootNode);

	RootNode.getState().show();
	NewNode.getState().show();

	return 0;
}