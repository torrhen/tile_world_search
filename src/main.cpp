#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/TreeSearch.h"

#include <iostream>
#include <vector>
#include <cstddef>

namespace TileSearch
{
	// tile is defined in Grid.h
	// tile positions must be positive and less than 4

	// tile starting positions
	namespace Start
	{
		Tile P(3, 0, 'P');
		Tile A(0, 0, 'A');
		Tile B(1, 0, 'B');
		Tile C(2, 0, 'C');		
	}

	// tile final positions
	namespace Goal
	{
		Tile P(3, 2, 'P');
		Tile A(0, 0, 'A');
		Tile B(1, 0, 'B');
		Tile C(2, 0, 'C');		
	}
}

int main()
{
	// ===========================================================================

	using namespace TileSearch;

	Grid StartGrid(Start::P, Start::A, Start::B, Start::C);
	Grid GoalGrid(Goal::P, Goal::A, Goal::B, Goal::C);

	Node RootNode(StartGrid);
	Node GoalNode(GoalGrid);

	breadth_first_tree_search(RootNode, GoalNode);

	std::cout << "Finished." << std::endl;

	return 0;
}