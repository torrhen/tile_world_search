#include "../include/Grid.h"
#include "../include/Node.h"

#include <memory>
#include <vector>
#include <iostream>

namespace TileSearch
{
	/* ============ Node Class =============== */

	Node::Node(const Grid &state)
		: state(state), parent(nullptr), depth(0)
	{

	}

	// create all possible child nodes
	void Node::generateChildren()
	{
		// create a new child node by moving tile P in all legal directions
	 	for (int i = 0; i < 4; ++i)
	 	{
	 		Node child(state);
	 		switch(i)
	 		{
	 			case 0:
	 			(child.state).movePUp();
	 			break;
	 			case 1:
				(child.state).movePLeft();
	 			break;
	 			case 2:
				(child.state).movePDown();
	 			break;
	 			case 3:
				(child.state).movePRight();
	 			break;
	 		}
	 		// if the movement of the p tile was successful then the child node state is different from its parents 
	 		if (!(child.getState() == getState()))
	 		{	
	 			child.depth = getDepth() + 1;
	 			child.parent = std::make_shared<Node>(*this);
	 			children.push_back(child);
	 		}
	 	}
	}

	 Grid Node::getState() const
	 {
		 return state;
	 }

	 Node* Node::getParent() const
	 {
	 	return parent.get();
	 }

	 std::size_t Node::getDepth() const
	 {
	 	return depth;
	 }

	 std::vector<Node> Node::getChildren() const
	 {
	 	return children;
	 }
}