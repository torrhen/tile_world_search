#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/TreeSearch.h"

#include <iostream>
#include <vector>

namespace TileSearch
{
	// tile is defined in Grid.h

	// set the starting positions of each tile in the grid
	namespace Start
	{
		// tile start positions must not be lower than 0 or greater than 3
		tile P = {std::make_pair(3, 0), 'P'};
		tile A = {std::make_pair(0, 0), 'A'};
		tile B = {std::make_pair(1, 0), 'B'};
		tile C = {std::make_pair(2, 0), 'C'};		
	}

	// set the final positions of each tile in the grid
	namespace Goal
	{
		// tile goal positions must not be lower than 0 or greater than 3
		tile P = {std::make_pair(3, 0), 'P'};
		tile A = {std::make_pair(0, 0), 'A'};
		tile B = {std::make_pair(1, 0), 'B'};
		tile C = {std::make_pair(2, 0), 'C'};
	}
}

int main()
{
	// ===========================================================================

	using namespace TileSearch;

	Grid StartGrid(Start::P, Start::A, Start::B, Start::C);

	Node RootNode(StartGrid);

	Grid GoalGrid(Goal::P, Goal::A, Goal::B, Goal::C);

	Node GoalNode(GoalGrid);

	DepthFirstTreeSearch b(RootNode, GoalNode);

	b.run();

	b.displaySolution();
	std::cout << b.getTimeComplexity() << std::endl;
	std::cout << b.getSpaceComplexity() << std::endl;

	std::cout << "Finished." << std::endl;

	return 0;
}