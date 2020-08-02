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

	// tree search functions
	namespace Tree
	{
		void breadth_first_search(const Node& Root, const Node& Goal);
		void depth_first_search(const Node& Root, const Node& Goal);
		void iterative_deepening_search(const Node& Root, const Node& Goal);
		void a_star_search(const Node& Root, const Node& Goal);		
	}

	// graph search functions (coming soon...)
	namespace Graph
	{

	}

	// push the children of the current node to the frontier of the seach function
	// the type of the frontier depends on the type of seach function used
	template <typename T>
	uint push_children(T& frontier, const std::vector<Node>& children)
	{
		for (std::vector<Node>::const_iterator it = cbegin(children); it != cend(children); ++it)
		{
			frontier.push(*it);
		}
		// return the number of children added to the frontier in order to monitor performance of the search function
		return children.size();
	}

	// used to order the nodes stored the priority queue used by A* search
	struct HeuristicComparator
	{
		bool operator()(const Node& Left, const Node& Right)
		{
			// nodes with a lower combined sum of their path from the root node and the estimated path to the goal are given priority
			// used as heuristic for A* search
			return (Left.get_path_cost() + Left.get_heuristic_cost()) >= (Right.get_path_cost() + Right.get_heuristic_cost());
		}
	};

	// display the solution path between the root node and the goal node of the tree to the console
	void show_solution(Node CurrentNode);
	// display the time complexity and space complexity of the search function to the console
	void show_performance(uint time_complexity, uint space_complexity);
	// overloaded function based on the type of frontier used by each search function
	const Node& get_next_node(const std::queue<Node>& frontier) { return frontier.front(); }
	const Node& get_next_node(const std::stack<Node>& frontier) { return frontier.top(); }
	const Node& get_next_node(const std::priority_queue<Node, std::vector<Node>, HeuristicComparator>& frontier) { return frontier.top(); }
}

#endif