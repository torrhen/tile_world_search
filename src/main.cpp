#include "../include/Grid.h"
#include "../include/Node.h"

#include <iostream>

int main()
{
	TileSearch::Grid s;
	TileSearch::Node n(s);


	std::cout << &n << std::endl;

	n.createChildren();
	std::cout << n.getDepth() << std::endl;
	std::cout << n.getParent() << std::endl;
	std::cout << n.getChildren().size() << std::endl;

	for (int i = 0; i < n.getChildren().size(); ++i)
	{
		n.getChildren()[i].getState().show();
		std::cout << n.getChildren()[i].getDepth() << std::endl;
		std::cout << n.getChildren()[i].getParent() << std::endl;
		std::cout << n.getChildren()[i].getChildren().size() << std::endl;

		if (i == 2)
		{
			TileSearch::Node b(n.getChildren()[i]);
			b.getState().show();
			std::cout << &b << std::endl;
			b.createChildren();
			for (int j = 0; j < b.getChildren().size(); ++j)
			{
				b.getChildren()[j].getState().show();
				std::cout << b.getChildren()[j].getDepth() << std::endl;
				std::cout << b.getChildren()[j].getParent() << std::endl;
				std::cout << b.getChildren()[j].getChildren().size() << std::endl;
			}
		}
		else
		{

		}
	}

	std::cout << "Finished." << std::endl;

	return 0;
}