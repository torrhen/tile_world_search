#ifndef TREE_SEARCH_H
#define TREE_SEARCH_H

#include "Grid.h"
#include "Node.h"

#include <vector>

namespace TileSearch
{	
	typedef unsigned int uint;

	void breadth_first_tree_search(const Node& root_node, const Node& goal_node);
	void depth_first_tree_search(const Node& root_node, const Node& goal_node);

	template <typename T>
	uint push_children_to_frontier(const std::vector<Node>& node_children, T& frontier)
	{
		uint num_children = 0;
		for (std::vector<Node>::const_iterator it = cbegin(node_children); it != cend(node_children); ++it)
		{
    		frontier.push(*it);
    		num_children++;
		}

		return num_children;
	}

	void show_solution(Node current_node);
	void show_performance(uint time_complexity, uint space_complexity);

}

#endif