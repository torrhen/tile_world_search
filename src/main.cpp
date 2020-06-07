#include "../lib/Grid.h"
#include "../lib/Node.h"

#include <iostream>

int main()
{
	TileSearch::Grid s;
	TileSearch::Node n(s);

	n.getState().show();

	return 0;
}