#ifndef SEARCH_H
#define SEARCH_H

#include "Grid.h"
#include "Node.h"

#include <vector>
#include <queue>
#include <stack>

namespace TileSearch
{	
	typedef unsigned int uint;

	namespace Tree
	{
		void breadth_first_search(const Node& Root, const Node& Goal);
		void depth_first_search(const Node& Root, const Node& Goal);
		void iterative_deepening_search(const Node& Root, const Node& Goal);
		void a_star_search(Node& Root, const Node& Goal);		
	}

	template <typename T>
	uint push_children(T& frontier, const std::vector<Node>& children)
	{
		for (std::vector<Node>::const_iterator it = cbegin(children); it != cend(children); ++it)
		{
			frontier.push(*it);
		}
		return children.size();
	}

	struct HeuristicComparator
	{
		bool operator()(const Node& Left, const Node& Right)
		{
			// may need to change comparator operator here
			return (Left.get_path_cost() + Left.get_heuristic_cost()) >= (Right.get_path_cost() + Right.get_heuristic_cost());
		}
	};

	void show_solution(Node CurrentNode);
	void show_performance(uint time_complexity, uint space_complexity);

	const Node& get_next_node(const std::queue<Node>& frontier);
	const Node& get_next_node(const std::stack<Node>& frontier);
	const Node& get_next_node(const std::priority_queue<Node, std::vector<Node>, HeuristicComparator>& frontier);
}

#endif