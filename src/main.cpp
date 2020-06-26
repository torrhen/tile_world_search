#include "../include/Grid.h"
// #include "../include/Node.h"

#include <iostream>

namespace TileSearch
{
	// tile is defined in Grid.h

	// set the starting positions of each tile in the grid
	namespace Start
	{
		tile P = {std::make_pair(3, 0), 'P'};
		tile A = {std::make_pair(0, 0), 'A'};
		tile B = {std::make_pair(1, 0), 'B'};
		tile C = {std::make_pair(2, 0), 'C'};		
	}

	// set the final positions of each tile in the grid
	namespace Goal
	{
		tile P = {std::make_pair(3, 0), 'P'};
		tile A = {std::make_pair(1, 2), 'A'};
		tile B = {std::make_pair(1, 1), 'B'};
		tile C = {std::make_pair(1, 0), 'C'};
	}
}

int main()
{
	// ===========================================================================

	using namespace TileSearch;

	Grid StartGrid(Start::P, Start::A, Start::B, Start::C);

	StartGrid.show();

	Grid NormalGrid(StartGrid);
	NormalGrid.show();
	NormalGrid.movePLeft();
	NormalGrid.movePLeft();
	NormalGrid.show();

	Grid GoalGrid(Goal::P, Goal::A, Goal::B, Goal::C);

	GoalGrid.show();

	Grid i(NormalGrid);
	i.movePUp();
	i.show();

	NormalGrid = i;

	NormalGrid.movePLeft();
	NormalGrid.movePUp();
	NormalGrid.movePRight();
	NormalGrid.movePDown();
	NormalGrid.show();

	std::cout << std::boolalpha << (i == NormalGrid) << std::endl;

	// ===========================================================================

	// TileSearch::StartGrid s;

	// TileSearch::RootNode r(s);

	// std::cout << r.getDepth() << std::endl;
	// std::cout << r.getParent() << std::endl;
	// r.getState()->show();

	// std::cout << &n << std::endl;

	// n.createChildren();
	// std::cout << n.getDepth() << std::endl;
	// std::cout << n.getParent() << std::endl;
	// std::cout << n.getChildren().size() << std::endl;
	// n.getState().show();

	// for (int i = 0; i < n.getChildren().size(); ++i)
	// {
		
	// 	n.getChildren().at(i).getState().show();
	// 	std::cout << n.getChildren().at(i).getDepth() << std::endl;
	// 	std::cout << n.getChildren().at(i).getParent() << std::endl;
	// 	std::cout << n.getChildren().at(i).getChildren().size() << std::endl;

	// 	if (i == 1)
	// 	{
	// 		TileSearch::Node b(n.getChildren().at(i));
	// 		b.getState().show();
	// 		std::cout << &b << std::endl;
	// 		b.createChildren();
	// 		for (int j = 0; j < b.getChildren().size(); ++j)
	// 		{
	// 			b.getChildren().at(j).getState().show();
	// 			std::cout << b.getChildren().at(j).getDepth() << std::endl;
	// 			std::cout << b.getChildren().at(j).getParent() << std::endl;
	// 			std::cout << b.getChildren().at(j).getChildren().size() << std::endl;
	// 			std::cout << std::boolalpha << b.getChildren().at(j).getState().isGoal() << std::endl;
	// 		}
	// 	}
	// 	else
	// 	{

	// 	}
	// }

	std::cout << "Finished." << std::endl;

	return 0;
}