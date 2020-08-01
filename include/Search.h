#ifndef SEARCH_H
#define SEARCH_H

#include "Grid.h"
#include "Node.h"

#include <vector>
#include <queue>
#include <stack>

#include <iostream>

namespace TileSearch
{	
	typedef unsigned int uint;

	namespace Tree
	{
		void breadth_first_search(const Node& Root, const Node& Goal);
		void depth_first_search(const Node& Root, const Node& Goal);
		void iterative_deepening_search(const Node& Root, const Node& Goal);
		void a_star_search(const HeuristicNode& Root, const HeuristicNode& Goal);		
	}

	template <typename T>
	uint push_children(T& frontier, Node& CurrentNode)
	{
		CurrentNode.expand();
		for (std::vector<Node>::const_iterator it = cbegin(CurrentNode.get_children()); it != cend(CurrentNode.get_children()); ++it)
		{
    		frontier.push(*it);
		}
		return CurrentNode.get_children().size();
	}

	const Node& get_next_node(const std::queue<Node>& frontier);
	const Node& get_next_node(const std::stack<Node>& frontier);
	const HeuristicNode& get_next_node(const std::priority_queue<HeuristicNode> frontier);

	void show_solution(Node CurrentNode);
	void show_performance(uint time_complexity, uint space_complexity);

}

#endif