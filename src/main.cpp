#include "grid.hpp"
#include "node.hpp"
#include "../include/Search.h"

#include <iostream>
#include <cstdint>

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

	std::uint32_t search_type;
	std::uint32_t search_method;

	Grid StartGrid(Start::P, Start::A, Start::B, Start::C);
	Grid GoalGrid(Goal::P, Goal::A, Goal::B, Goal::C);

	Node RootNode(StartGrid);
	Node GoalNode(GoalGrid);

	std::cout << "Pick a search type...\n\n";
	std::cout << "[1] Tree Search\n[2] Graph Search\n\n";
	std::cin >> search_type;

	if (search_type != 1 && search_type != 2)
	{
		std::cout << "Invalid search type.\n";
		return 0;
	}

	std::cout << "Pick a search method...\n\n";
	std::cout << "[1] Breadth-First Search\n[2] Iterative Deepening Search\n[3] A* Search\n\n";
	std::cin >> search_method;

	if (search_method != 1 && search_method != 2 && search_method != 3)
	{
		std::cout << "Invalid search method.\n";
		return 0;
	}

	switch (search_type)
	{
		case 1:
		switch (search_method)
		{
			case 1:
			std::cout << "Breadth-first tree search selected.\n";
			Tree::breadth_first_search(RootNode, GoalNode);
			break;
			case 2:
			std::cout << "Iterative deepening tree search selected.\n";
			Tree::iterative_deepening_search(RootNode, GoalNode);
			break;
			case 3:
			std::cout << "A* tree search selected.\n";
			Tree::a_star_search(RootNode, GoalNode);
		}
		break;
		case 2:
		switch (search_method)
		{
			case 1:
			std::cout << "Breadth-first graph search selected.\n";
			Graph::breadth_first_search(RootNode, GoalNode);
			break;
			case 2:
			std::cout << "Iterative deepening graph search selected.\n";
			Graph::iterative_deepening_search(RootNode, GoalNode);
			break;
			case 3:
			std::cout << "A* graph search selected.\n";
			Graph::a_star_search(RootNode, GoalNode);
		}
	}
	
	std::cout << "Finished." << std::endl;
	return 0;
}