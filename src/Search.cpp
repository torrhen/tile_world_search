#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/Search.h"

#include <iostream>

namespace TileSearch
{
	/* ========== Tree Search Functions ========== */

	namespace Tree
	{
		void breadth_first_search(const Node& Root, const Node& Goal)
		{
			std::queue<Node> frontier;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting breadth first tree search... \n";
			frontier.push(Root);
			num_nodes_generated++;

			while (!frontier.empty())
			{
				if (frontier.size() >= max_nodes_generated) max_nodes_generated = frontier.size();

				Node Current(get_next_node(frontier));
				frontier.pop();

				if (Current == Goal)
				{
					std::cout << "Goal node found.\n";
					std::cout << "Breadth first tree search complete.\n";
					std::cout << "Generating solution...\n";
					show_solution(Current);
					show_performance(num_nodes_generated, max_nodes_generated);
					return;
				}
				Current.expand();
				num_nodes_generated += push_children(frontier, Current.get_children());
			}
			std::cout << "No solution found.\n";
		}

		void depth_first_search(const Node& Root, const Node& Goal)
		{
			std::stack<Node> frontier;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting depth first tree search... \n";
			frontier.push(Root);
			num_nodes_generated++;

			while (!frontier.empty())
			{
				if (frontier.size() >= max_nodes_generated) max_nodes_generated = frontier.size();

				Node Current(get_next_node(frontier));
				frontier.pop();

				if (Current == Goal)
				{
					std::cout << "Goal node found.\n";
					std::cout << "Depth first tree search complete.\n";
					std::cout << "Generating solution...\n";
					show_solution(Current);
					show_performance(num_nodes_generated, max_nodes_generated);
					return;
				}
				Current.expand();
				num_nodes_generated += push_children(frontier, Current.get_children());
			}
			std::cout << "No solution found.\n";
		}

		void iterative_deepening_search(const Node& Root, const Node& Goal)
		{
			uint depth_limit = 0;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting iterative deepening tree search... \n";

			while (true)
			{
				std::stack<Node> frontier;
				std::cout << "Starting depth limited tree search... \t(depth limit: " << depth_limit << ")\n";
				frontier.push(Root);
				num_nodes_generated++;

				while (!frontier.empty())
				{
					if (frontier.size() >= max_nodes_generated) max_nodes_generated = frontier.size();

					Node Current(get_next_node(frontier));
					frontier.pop();

					if (Current == Goal)
					{
						std::cout << "Goal node found.\n";
						std::cout << "Iterative deepening tree search complete.\n";
						std::cout << "Generating solution...\n";
						show_solution(Current);
						show_performance(num_nodes_generated, max_nodes_generated);
						return;
					}

					if (Current.get_depth() < depth_limit)
					{
						Current.expand();
						num_nodes_generated += push_children(frontier, Current.get_children());
					}

				}
				std::cout << "No solution found. Increasing the depth limit... \n";
				depth_limit++;
			}
		}

		void a_star_search(Node& Root, const Node& Goal)
		{
			std::priority_queue<Node, std::vector<Node>, HeuristicComparator> frontier;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting A* tree search... \n";
			Root.set_heuristic_cost(Goal);
			frontier.push(Root);
			num_nodes_generated++;

			while (!frontier.empty())
			{
				if (frontier.size() >= max_nodes_generated) max_nodes_generated = frontier.size();
		
				Node Current(get_next_node(frontier));
				frontier.pop();

				if (Current == Goal)
				{
					std::cout << "Goal node found.\n";
					std::cout << "A* tree search complete.\n";
					std::cout << "Generating solution...\n";
					show_solution(Current);
					show_performance(num_nodes_generated, max_nodes_generated);
					return;
				}
				Current.expand();
				for (std::vector<Node>::const_iterator it = begin(Current.get_children()); it != end(Current.get_children()); ++it)
				{
					it->set_heuristic_cost(Goal);
				}
				num_nodes_generated += push_children(frontier, Current.get_children());
			}
			std::cout << "No solution found.\n";
		}
	}

	/* ========== End Tree Search Functions ========== */

	void show_solution(Node Current)
	{
		while (Current.get_parent() != nullptr)
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

	const Node& get_next_node(const std::queue<Node>& frontier)
	{
		return frontier.front();
	}
	
	const Node& get_next_node(const std::stack<Node>& frontier)
	{
		return frontier.top();
	}
	
	const Node& get_next_node(const std::priority_queue<Node, std::vector<Node>, HeuristicComparator>& frontier)
	{
		return frontier.top();
	}
}