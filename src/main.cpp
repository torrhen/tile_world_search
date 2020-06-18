#include "../include/Grid.h"
// #include "../include/Node.h"

#include <iostream>

int main()
{
	TileSearch::StartGrid s;

	s.show();


	TileSearch::StandardGrid n(s);
	n.show();
	n.movePLeft();
	n.movePLeft();
	n.show();
	n.movePRight();
	n.movePRight();
	n.show();

	std::cout << std::boolalpha << n.isIdenticalTo(s) << std::endl;


	TileSearch::GoalGrid g;

	g.show();

	// TileSearch::Node n(s);

	// std::cout << std::boolalpha << s.isGoal() << std::endl;


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