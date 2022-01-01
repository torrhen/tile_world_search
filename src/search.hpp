#ifndef SEARCH_H
#define SEARCH_H

#include "grid.hpp"
#include "node.hpp"

#include <vector>
#include <queue>
#include <stack>

namespace tile_world_search
{	
	enum class Structure : std::uint32_t
	{
		TREE = 0, GRAPH = 1
	};

	enum class Heuristic : std::uint32_t
	{
		MISPLACED_TILES = 0, MANHATTAN_DISTANCE  = 1
	};

	bool has_been_expanded(const std::vector<Node>& expanded_nodes, const Node& CurrentNode);
	void breadth_first_search(const Structure type, const Node& Root, const Node& Goal);
	void iterative_deepening_search(const Structure type, const Node& Root, const Node& Goal);
	void a_star_search(const Structure type, const Node& Root, const Node& Goal, Heuristic heuristic_method);
	// push all generated children of the current node to the frontier
	// the type of the frontier will depend on the search function used
	template <typename T>
	std::uint32_t push_children(T& frontier, const std::vector<Node>& children)
	{
		for (auto it = children.cbegin(); it != children.cend(); ++it)
		{
			frontier.push(std::move(*it));
		}
		// return the number of children added to the frontier
		return children.size();
	}
	// display the solution path found to the console
	void show_solution(Node CurrentNode);
}

#endif