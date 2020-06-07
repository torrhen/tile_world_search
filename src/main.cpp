#include "../include/Grid.h"
#include "../include/Node.h"

#include <iostream>

int main()
{
	TileSearch::Grid s;
	TileSearch::Node n(s);

	n.getState().show();

	return 0;
}