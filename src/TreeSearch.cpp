#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/TreeSearch.h"

#include <vector>
#include <queue>
#include <stack>
#include <iterator>
#include <iostream>

namespace TileSearch
{
	/* ========== TreeSearch Class ========== */

	template<typename T>
	TreeSearch<T>::TreeSearch(const Node& root, const Node& goal)
		: root(root), goal(goal), total_nodes(0), max_nodes(0)
	{}

	template<typename T>
	// generate child nodes and add them to the frontier
	void TreeSearch<T>::expand(Node& node)
	{
		// create children
		node.createChildren();

		// add children to the frontier
		for (std::vector<Node>::const_iterator it = begin(node.getChildren()); it != end(node.getChildren()); ++it)
		{
    		frontier.push(*it);
    		total_nodes++;
		}
	}

	// generate the solution path from goal node to root node of the tree
	template<typename T>
	void TreeSearch<T>::generateSolution(Node node)
	{
		while(node.getParent() != nullptr)
		{
			solution.push_back(node);
			node = *node.getParent();
		}
		solution.push_back(std::move(node));
	}

	template<typename T>
	void TreeSearch<T>::setup()
	{
		frontier.push(root);
		total_nodes++;
		max_nodes++;
	}

	template<typename T>
	void TreeSearch<T>::updateSpaceComplexity()
	{
		if (frontier.size() >= max_nodes)
		{
			max_nodes = frontier.size();
		}
	}

	// display solution path to console
	template<typename T>
	void TreeSearch<T>::displaySolution() const
	{
		if (!solution.empty())
		{
			for (std::vector<Node>::const_reverse_iterator it = rbegin(solution); it != rend(solution); ++it)
			{
	    		it->getState().show();
			}
		}
	}

	// return total number of nodes generated by search 
	template<typename T>
	const unsigned int& TreeSearch<T>::getTimeComplexity() const
	{
		return total_nodes;
	}

	// return max number of nodes generated by search
	template<typename T>
	const unsigned int& TreeSearch<T>::getSpaceComplexity() const
	{
		return max_nodes;
	}

	/* ========== BreadthFirstTreeSearch Class ========== */

	// frontier for breadth-first search is FIFO 
	template class TreeSearch<std::queue<Node>>;

	BreadthFirstTreeSearch::BreadthFirstTreeSearch(const Node& root, const Node& goal)
		: TreeSearch(root, goal)
	{}

	int BreadthFirstTreeSearch::run()
	{
		std::cout << "Starting Breadth First Tree Search.\n";

		setup();

		while(!(frontier.front() == goal))
		{
			expand(frontier.front());
			frontier.pop();

			updateSpaceComplexity();

			// if there are no nodes on the frontier left to expend before the goal node has been found...
			if (frontier.empty())
			{
				// stop the search
				std::cout << "No Solution Found.\n";
				return 0;
			}
		}
		std::cout << "Goal Node Found.\nBreadth First Search Complete.\nGenerating Solution Path...";
		generateSolution(frontier.front());
		std::cout << "done.\n";
		return 0;
	}

	/* ========== DepthFirstTreeSearch Class ========== */

	// frontier for depth-first search is LIFO 
	template class TreeSearch<std::stack<Node>>;

	DepthFirstTreeSearch::DepthFirstTreeSearch(const Node& root, const Node& goal)
		: TreeSearch(root, goal)
	{}

	DepthFirstTreeSearch::run()
	{
		std::cout << "Starting Depth First Tree Search.\n";

		setup();

		while(!(frontier.top() == goal))
		{
			expand(frontier.top());
			frontier.pop();

			updateSpaceComplexity();

			// if there are no nodes on the frontier left to expend before the goal node has been found...
			if (frontier.empty())
			{
				// stop the search
				std::cout << "No Solution Found.\n";
				return 0;
			}
		}
		std::cout << "Goal Node Found.\nDepth First Search Complete.\nGenerating Solution Path...";
		generateSolution(frontier.top());
		std::cout << "done.\n";
		return 0;	
	}	

}