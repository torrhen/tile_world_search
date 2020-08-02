#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/Search.h"

#include <iostream>

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
		Tile P(3, 1, 'P');
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

	std::cout << "=====================================\n\n";
	Tree::breadth_first_search(RootNode, GoalNode);
	Tree::depth_first_search(RootNode, GoalNode);
	Tree::iterative_deepening_search(RootNode, GoalNode);
	Tree::a_star_search(RootNode, GoalNode);

	std::cout << "Finished." << std::endl;

	return 0;
}