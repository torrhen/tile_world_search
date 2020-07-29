#include "../include/Grid.h"
#include "../include/Node.h"

#include <memory>
#include <cstddef>
#include <vector>
#include <random>
#include <algorithm>

namespace TileSearch
{
	/* ============ Node Class =============== */

	Node::Node(const Grid& State)
		: State(State), parent(nullptr), depth(0)
	{}

	void Node::expand()
	{
		for (std::size_t i = 0; i < max_children; ++i)
		{
			Grid ChildState(get_state());
			switch(i)
	 		{
	 			case 0:
	 			(ChildState).move_P_up();
	 			break;
	 			case 1:
				(ChildState).move_P_left();
	 			break;
	 			case 2:
				(ChildState).move_P_down();
	 			break;
	 			case 3:
				(ChildState).move_P_right();
	 			break;
	 		}
	 		if (!(ChildState == get_state()))
	 		{
	 			children.emplace_back(ChildState);	
	 			children.back().depth = get_depth() + 1;
	 			children.back().parent = std::make_shared<Node>(*this);
	 		}
		}
		std::shuffle(children.begin(), children.end(), std::default_random_engine());
	}

	bool operator==(const Node& Left, const Node& Right)
	{
		return (&Left == &Right) || (Left.get_state() == Right.get_state());
	}
}