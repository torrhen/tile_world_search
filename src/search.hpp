#ifndef SEARCH_H
#define SEARCH_H

#include "grid.hpp"
#include "node.hpp"

#include <vector>
#include <queue>
#include <stack>

namespace TileSearch
{	
	// tree search functions
	namespace Tree
	{
		void breadth_first_search(const Node& Root, const Node& Goal);
		void iterative_deepening_search(const Node& Root, const Node& Goal);
		void a_star_search(const Node& Root, const Node& Goal);		
	}

	// graph search functions
	namespace Graph
	{
		bool has_been_expanded(const std::vector<Node>& expanded_nodes, const Node& CurrentNode);
		void breadth_first_search(const Node& Root, const Node& Goal);
		void iterative_deepening_search(const Node& Root, const Node& Goal);
		void a_star_search(const Node& Root, const Node& Goal);	
	}

	// push all generated children of the current node to the frontier
	// the type of the frontier will depend on the search function used
	template <typename T>
	uint push_children(T& frontier, const std::vector<Node>& children)
	{
		for (auto it = children.cbegin(); it != children.cend(); ++it)
		{
			frontier.push(*it);
		}
		// return the number of children added to the frontier in order to monitor the performance of the search function
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
	// overload function based on the type of frontier used by each search function
	const Node& get_next_node(const std::queue<Node>& frontier);
	const Node& get_next_node(const std::stack<Node>& frontier);
	const Node& get_next_node(const std::priority_queue<Node, std::vector<Node>, HeuristicComparator>& frontier);
}

#endif