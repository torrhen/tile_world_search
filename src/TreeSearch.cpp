#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/TreeSearch.h"

#include <iostream>

namespace TileSearch
{
	void breadth_first_tree_search(const Node& Root, const Node& Goal)
	{
		std::queue<Node> frontier;
		uint num_nodes_generated = 0;
		uint max_nodes_generated = 0;

		std::cout << "Starting Breadth First Tree Search.\n";

		frontier.push(Root);
		num_nodes_generated++;
		max_nodes_generated++;

		Node Current(get_next_node(frontier));

		while(!(Current == Goal))
		{
			num_nodes_generated += push_children(frontier, Current);
			frontier.pop();

			if (frontier.size() >= max_nodes_generated) { max_nodes_generated = frontier.size(); }

			// if there are no nodes on the frontier left to expend before the goal node has been found...
			if (frontier.empty())
			{
				// stop the search
				std::cout << "No Solution Found.\n";
				return;
			}
			else
			{
				Current = get_next_node(frontier);
			}
		}
		std::cout << "Goal Node Found.\nBreadth First Search Complete.\nGenerating Solution Path...";
		std::cout << "done.\n";
		
		show_solution(Current);
		show_performance(num_nodes_generated, max_nodes_generated);
	}

	void depth_first_tree_search(const Node& Root, const Node& Goal)
	{
		std::stack<Node> frontier;
		uint num_nodes_generated = 0;
		uint max_nodes_generated = 0;

		std::cout << "Starting Depth First Tree Search.\n";

		frontier.push(Root);
		num_nodes_generated++;
		max_nodes_generated++;

		Node Current(get_next_node(frontier));

		while(!(Current == Goal))
		{
			num_nodes_generated += push_children(frontier, Current);
			frontier.pop();

			if (frontier.size() >= max_nodes_generated) { max_nodes_generated = frontier.size(); }

			// if there are no nodes on the frontier left to expend before the goal node has been found...
			if (frontier.empty())
			{
				// stop the search
				std::cout << "No Solution Found.\n";
				return;
			}
			else
			{
				Current = get_next_node(frontier);
			}
		}
		std::cout << "Goal Node Found.\nDepth First Search Complete.\nGenerating Solution Path...";
		std::cout << "done.\n";
		
		show_solution(Current);
		show_performance(num_nodes_generated, max_nodes_generated);
	}

	const Node& get_next_node(const std::queue<Node>& frontier) { return frontier.front(); }
	const Node& get_next_node(const std::stack<Node>& frontier) { return frontier.top(); }

	void show_solution(Node Current)
	{
		while(Current.get_parent() != nullptr)
		{
			Current.get_state().show();
			Current = *Current.get_parent();
		}
		Current.get_state().show();
	}

	void show_performance(uint time_complexity, uint space_complexity)
	{
		std::cout << "=================================\n";
		std::cout << "Time Complexity:\t" << time_complexity << "\n";
		std::cout << "Space Complexity:\t" << space_complexity << "\n";
		std::cout << "=================================\n";
	}
}