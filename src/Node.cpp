#include "../include/Grid.h"
#include "../include/Node.h"

#include <memory>
#include <vector>

namespace TileSearch
{
	/* ============ Node Class =============== */

	Node::Node(const Grid &state)
		: state(state), parent(nullptr), depth(0)
	{

	}

	void Node::createChildren()
	{
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
	 		if (!(child.getState() == getState()))
	 		{
	 			child.depth = getDepth() + 1;
	 			child.parent = std::make_shared<Node>(*this);
	 			children.push_back(std::move(child));		
	 		}
		}
	}

	const Grid& Node::getState() const
	{
		 return state;
	}

	const Node* Node::getParent() const
	{
	 	return parent.get();
	}

	const unsigned int& Node::getDepth() const
	{
	 	return depth;
	}

	const std::vector<Node>& Node::getChildren() const
	{
		return children;
	}
}