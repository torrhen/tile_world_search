#include "grid.hpp"
#include "node.hpp"
#include "search.hpp"

#include <iostream>
#include <cstdint>

namespace tile_world_search
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
	using namespace tile_world_search;

	std::uint32_t search_type;
	std::uint32_t search_method;

	Grid StartGrid(Start::P, Start::A, Start::B, Start::C);
	Grid GoalGrid(Goal::P, Goal::A, Goal::B, Goal::C);

	Node RootNode(StartGrid);
	Node GoalNode(GoalGrid);

	std::cout << "\n[SELECT]\tSearch type\n";
	std::cout << "...\n";
	std::cout << "[1]\t\tTree Search\n[2]\t\tGraph Search\n";
	std::cout << "\n";

	std::cin >> search_type;

	if (search_type != 1 && search_type != 2)
	{
		std::cout << "Invalid search type.\n";
		return 0;
	}

	std::cout << "\n[SELECT]\tSearch method\n";
	std::cout << "...\n";
	std::cout << "[1]\t\tBreadth-First Search\n[2]\t\tIterative Deepening Search\n[3]\t\tA* Search\n";
	std::cout << "\n";

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
			std::cout << "\n[SELECTED]\tBreadth-first tree search\n";
			breadth_first_search(Structure::TREE, RootNode, GoalNode);
			break;
			case 2:
			std::cout << "\n[SELECTED]\tIterative deepening tree search\n";
			iterative_deepening_search(Structure::TREE, RootNode, GoalNode);
			break;
			case 3:
			std::cout << "\n[SELECTED]\tA* tree search\n";
			a_star_search(Structure::TREE, RootNode, GoalNode);
		}
		break;
		case 2:
		switch (search_method)
		{
			case 1:
			std::cout << "\n[SELECTED]\tBreadth-first graph search\n";
			breadth_first_search(Structure::GRAPH, RootNode, GoalNode);
			break;
			case 2:
			std::cout << "\n[SELECTED]\tIterative deepening graph search\n";
			iterative_deepening_search(Structure::GRAPH, RootNode, GoalNode);
			break;
			case 3:
			std::cout << "\n[SELECTED]\tA* graph search\n";
			a_star_search(Structure::GRAPH, RootNode, GoalNode);
		}
	}
	return 0;
}