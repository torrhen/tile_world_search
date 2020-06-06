#include "../lib/Grid.h"
// #include "../lib/Node.h"

#include <iostream>

int main()
{
	TileSearch::Grid g;

	g.show();

	g.movePUp();

	g.show();

	return 0;
}