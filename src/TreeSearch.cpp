#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/TreeSearch.h"

#include <vector>
#include <queue>
#include <stack>
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

		Node Current(frontier.front());

		while(!(Current == Goal))
		{
			Current.expand();

			num_nodes_generated += push_children_to_frontier(Current.get_children(), frontier);

			if (frontier.size() >= max_nodes_generated)
			{
				max_nodes_generated = frontier.size();
			}

			frontier.pop();

			// if there are no nodes on the frontier left to expend before the goal node has been found...
			if (frontier.empty())
			{
				// stop the search
				std::cout << "No Solution Found.\n";
				return;
			}
			else
			{
				Current = frontier.front();
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

		Node Current(frontier.top());

		while(!(Current == Goal))
		{
			Current.expand();

			num_nodes_generated += push_children_to_frontier(Current.get_children(), frontier);

			if (frontier.size() >= max_nodes_generated)
			{
				max_nodes_generated = frontier.size();
			}

			frontier.pop();

			// if there are no nodes on the frontier left to expend before the goal node has been found...
			if (frontier.empty())
			{
				// stop the search
				std::cout << "No Solution Found.\n";
				return;
			}
			else
			{
				Current = frontier.top();
			}
		}
		std::cout << "Goal Node Found.\nDepth First Search Complete.\nGenerating Solution Path...";
		std::cout << "done.\n";
		show_solution(Current);
		show_performance(num_nodes_generated, max_nodes_generated);
	}

	void show_solution(Node Current)
	{
		std::vector<Node> solution;
		while(Current.get_parent() != nullptr)
		{
			Current.get_state().show();
			Current = *Current.get_parent();
		}
		Current.get_state().show();
	}

	void show_performance(uint time_complexity, uint space_complexity)
	{
		std::cout << "=========================================\n";
		std::cout << "Time Complexity:\t\t" << time_complexity << "\n";
		std::cout << "Space Complexity:\t\t" << space_complexity << "\n";
		std::cout << "=========================================\n";
	}
}