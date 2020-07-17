#include "../include/Grid.h"
#include "../include/Node.h"

#include <memory>
#include <vector>
#include <random>
#include <algorithm>

namespace TileSearch
{
	/* ============ Node Class =============== */

	Node::Node(const Grid &state)
		: state(state), parent(nullptr), depth(0)
	{}

	void Node::createChildren()
	{
		for (int i = 0; i < 4; ++i)
		{
			Grid child_state(getState());
			switch(i)
	 		{
	 			case 0:
	 			(child_state).movePUp();
	 			break;
	 			case 1:
				(child_state).movePLeft();
	 			break;
	 			case 2:
				(child_state).movePDown();
	 			break;
	 			case 3:
				(child_state).movePRight();
	 			break;
	 		}
	 		if (!(child_state == getState()))
	 		{
	 			children.emplace_back(child_state);	
	 			children.back().depth = getDepth() + 1;
	 			children.back().parent = std::make_shared<Node>(*this);
	 		}
		}
		// shuffle the order of children
		auto rnd = std::random_device();
		auto rng = std::default_random_engine(rnd());
		std::shuffle(begin(children), end(children), rng);
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

	bool operator==(const Node& lhs, const Node& rhs)
	{
		if (lhs.getState() == rhs.getState())
		{
			return true;
		}
		return false;
	}
}