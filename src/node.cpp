#include "grid.hpp"
#include "node.hpp"

#include <cstddef>
#include <random>
#include <algorithm>

namespace tile_world_search
{
	/* ============ Node Class =============== */

	Node::Node(const Grid& State)
		: State(State), parent(nullptr), depth(0), path_cost(0), heuristic_cost(0)
	{}

	std::uint32_t Node::total_nodes_generated = 0;
	std::uint32_t Node::max_nodes_generated = 0;

	void Node::expand()
	{
		// generate the state of every possible child node by moving the player tile
		for (std::size_t n = 0; n < max_children; ++n)
		{
			// copy the current state of the node
			Grid ChildState = get_state();
			switch(n)
	 		{
	 			case 0:
	 			ChildState.move_player(Direction::UP);
	 			break;
	 			case 1:
				ChildState.move_player(Direction::LEFT);
	 			break;
	 			case 2:
				ChildState.move_player(Direction::DOWN);
	 			break;
	 			case 3:
				ChildState.move_player(Direction::RIGHT);
	 			break;
	 		}
	 		// only keep child nodes with a state different from their parent
	 		// if a child node has the same state as their parent then the player move was unsuccessful
	 		if (!(ChildState == get_state()))
	 		{
	 			// create a node directly on the vector with the moved child state
	 			// child state memory can be reused above for the next potential child
	 			children.emplace_back(std::move(ChildState));
	 			// link the child node with its parent
	 			// vector element is now the one with ownership of the child node after the move
	 			children.back().parent = std::make_shared<Node>(*this);
	 			children.back().depth = get_depth() + 1;
	 			children.back().path_cost = get_path_cost() + 1;
	 		}
		}
		// shuffle the order of child nodes to help search functions avoid sub-optimal paths
		std::shuffle(children.begin(), children.end(), std::default_random_engine());
	}

	// set the heuristic cost of the node based on the chosen heuristic function
	void Node::set_heuristic_cost(const Node& Goal, std::uint32_t(*func)(const Grid&, const Grid&)) const
	{
		heuristic_cost = func(get_state(), Goal.get_state());
	}

	/* ============ End Node Class =============== */

	bool operator==(const Node& Left, const Node& Right)
	{
		return (&Left == &Right) || (Left.get_state() == Right.get_state());
	}
}