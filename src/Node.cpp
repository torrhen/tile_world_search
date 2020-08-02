#include "../include/Grid.h"
#include "../include/Node.h"

#include <cstddef>
#include <random>
#include <algorithm>

namespace TileSearch
{
	/* ============ Node Class =============== */

	Node::Node(const Grid& State)
		: State(State), parent(nullptr), depth(0), path_cost(0), heuristic_cost(0)
	{}

	void Node::expand()
	{
		// generate the state of every possible child node by moving the P tile
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
	 		// only keep child nodes with a state different from their parent
	 		// if a child node has the same state as their parent then the movement of the P tile was unsuccessful in that direction
	 		if (!(ChildState == get_state()))
	 		{
	 			// create a node directly on the vector using the legal grid state to save an object copy
	 			children.emplace_back(ChildState);
	 			// link the child node with its parent
	 			children.back().parent = std::make_shared<Node>(*this);
	 			children.back().depth = get_depth() + 1;
	 			children.back().path_cost = get_path_cost() + 1;
	 		}
		}
		// shuffle the order of child nodes to help search functions avoid sub-optimal paths
		std::shuffle(children.begin(), children.end(), std::default_random_engine());
	}

	void Node::set_heuristic_cost(const Node& Goal) const
	{
		heuristic_cost = get_state().manhattan_distance_to(Goal.get_state());
	}

	/* ============ End Node Class =============== */

	bool operator==(const Node& Left, const Node& Right)
	{
		return (&Left == &Right) || (Left.get_state() == Right.get_state());
	}
}