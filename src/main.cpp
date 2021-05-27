#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/Search.h"

#include <iostream>

namespace TileSearch
{
	// set the starting configuration of the root node
	namespace Start
	{
		Tile P(3, 0, Letter::P);
		Tile A(0, 0, Letter::A);
		Tile B(1, 0, Letter::B);
		Tile C(2, 0, Letter::C);		
	}

	// set the final configuration of the goal node
	namespace Goal
	{
		Tile P(3, 0, Letter::P);
		Tile A(1, 2, Letter::A);
		Tile B(1, 1, Letter::B);
		Tile C(1, 0, Letter::C);		
	}
}

int main()
{

	using namespace TileSearch;

	Grid StartGrid(Start::P, Start::A, Start::B, Start::C);
	Grid GoalGrid(Goal::P, Goal::A, Goal::B, Goal::C);

	Node RootNode(StartGrid);
	Node GoalNode(GoalGrid);

	//std::cout << "=====================================\n\n";
	// run tree searches
	// Tree::breadth_first_search(RootNode, GoalNode);
	// Tree::iterative_deepening_search(RootNode, GoalNode);
	// Tree::a_star_search(RootNode, GoalNode);

	// run graph searches
	// Graph::breadth_first_search(RootNode, GoalNode);
	// Graph::iterative_deepening_search(RootNode, GoalNode);
	// Graph::a_star_search(RootNode, GoalNode);

	std::cout << "Finished." << std::endl;
	return 0;
}