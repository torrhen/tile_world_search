#include "../include/Grid.h"
#include "../include/Node.h"

#include <iostream>

int main()
{
	TileSearch::Grid s;
	TileSearch::Node n(s);

	n.createChildren();

	for (int i = 0; i < n.getChildren().size(); ++i)
	{
		n.getChildren()[i].getState().show();
	}

	return 0;
}