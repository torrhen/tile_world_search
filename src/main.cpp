#include "../include/Grid.h"
// #include "../include/Node.h"

#include <iostream>

// set the starting positions of each tile in the grid
namespace Start
{
	std::pair<int, int> P = std::make_pair(3, 0);
	std::pair<int, int> A = std::make_pair(0, 0);
	std::pair<int, int> B = std::make_pair(1, 0);
	std::pair<int, int> C = std::make_pair(2, 0);		
}

// set the final positions of each tile in the grid
namespace Goal
{
	std::pair<int, int> P = std::make_pair(3, 0);
	std::pair<int, int> A = std::make_pair(1, 2);
	std::pair<int, int> B = std::make_pair(1, 1);
	std::pair<int, int> C = std::make_pair(1, 0);
}


int main()
{
	// ===========================================================================

	TileSearch::StartGrid s(Start::P, Start::A, Start::B, Start::C);

	s.show();

	TileSearch::StandardGrid n(s);
	n.show();
	n.movePLeft();
	n.movePLeft();
	n.show();
	n.movePRight();
	n.movePRight();
	n.show();

	TileSearch::GoalGrid g(Goal::P, Goal::A, Goal::B, Goal::C);

	g.show();

	TileSearch::StandardGrid h(g);

	h.show();

	h = n;

	h.show();

	std::cout << std::boolalpha << (h == n) << std::endl;

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