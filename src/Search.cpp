#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/Search.h"

#include <iostream>

namespace TileSearch
{
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
					std::cout << "Breadth first search complete.\n";
					std::cout << "Generating solution...\n";
					show_solution(Current);
					show_performance(num_nodes_generated, max_nodes_generated);
					return;
				}
				num_nodes_generated += push_children(frontier, Current);
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
					std::cout << "Depth first search complete.\n";
					std::cout << "Generating solution...\n";
					show_solution(Current);
					show_performance(num_nodes_generated, max_nodes_generated);
					return;
				}
				num_nodes_generated += push_children(frontier, Current);
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
						std::cout << "Iterative deepening search complete.\n";
						std::cout << "Generating solution...\n";
						show_solution(Current);
						show_performance(num_nodes_generated, max_nodes_generated);
						return;
					}

					if (Current.get_depth() < depth_limit) num_nodes_generated += push_children(frontier, Current);

				}
				std::cout << "No solution found. Increasing the depth limit... \n";
				depth_limit++;
			}
		}

		void a_star_search([[maybe_unused]] const HeuristicNode& Root, [[maybe_unused]] const HeuristicNode& Goal)
		{
			return;
		}
	}

	const Node& get_next_node(const std::queue<Node>& frontier) { return frontier.front(); }
	const Node& get_next_node(const std::stack<Node>& frontier) { return frontier.top(); }
	const HeuristicNode& get_next_node(const std::priority_queue<HeuristicNode> frontier) { return frontier.top(); }

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
}