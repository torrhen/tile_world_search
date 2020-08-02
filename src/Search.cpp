#include "../include/Grid.h"
#include "../include/Node.h"
#include "../include/Search.h"

#include <iostream>

namespace TileSearch
{
	/* ========== Tree Search Functions ========== */

	namespace Tree
	{
		// breadth-first tree search
		void breadth_first_search(const Node& Root, const Node& Goal)
		{
			// nodes stored on the frontier are FIFO
			std::queue<Node> frontier;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting breadth first tree search... \n";
			Node CurrentNode(Root);
			frontier.push(CurrentNode);
			num_nodes_generated++;

			while (!frontier.empty())
			{
				// if the current frontier size is larger than the maximum size of the frontier before this point...
				if (frontier.size() >= max_nodes_generated)
					// update this maximum value
					max_nodes_generated = frontier.size();

				CurrentNode = get_next_node(frontier);
				frontier.pop();

				if (CurrentNode == Goal)
				{
					std::cout << "Goal node found.\nBreadth first tree search complete.\nGenerating solution...\n";
					show_solution(CurrentNode);
					show_performance(num_nodes_generated, max_nodes_generated);
					// stop the search
					return;
				}

				CurrentNode.expand();
				num_nodes_generated += push_children(frontier, CurrentNode.get_children());
			}
			std::cout << "No solution found.\n";
		}

		// depth-first tree search
		void depth_first_search(const Node& Root, const Node& Goal)
		{
			// nodes stored on the frontier are LIFO
			std::stack<Node> frontier;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting depth first tree search... \n";
			Node CurrentNode(Root);
			frontier.push(CurrentNode);
			num_nodes_generated++;

			while (!frontier.empty())
			{
				// if the current frontier size is larger than the maximum size of the frontier before this point...
				if (frontier.size() >= max_nodes_generated)
					// update this maximum value
					max_nodes_generated = frontier.size();

				CurrentNode = get_next_node(frontier);
				frontier.pop();

				if (CurrentNode == Goal)
				{
					std::cout << "Goal node found.\nDepth first tree search complete.\nGenerating solution...\n";
					show_solution(CurrentNode);
					show_performance(num_nodes_generated, max_nodes_generated);
					// stop the search
					return;
				}

				CurrentNode.expand();
				num_nodes_generated += push_children(frontier, CurrentNode.get_children());
			}
			std::cout << "No solution found.\n";
		}

		// iterative deepening tree search
		void iterative_deepening_search(const Node& Root, const Node& Goal)
		{
			// store the current depth limit of search
			uint depth_limit = 0;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting iterative deepening tree search... \n";
			while (true)
			{
				// nodes stored on the frontier are LIFO
				std::stack<Node> frontier;
				// start a new iteration of depth-limited tree search
				std::cout << "Starting depth limited tree search... \t(depth limit: " << depth_limit << ")\n";
				Node CurrentNode(Root);
				frontier.push(CurrentNode);
				num_nodes_generated++;

				while (!frontier.empty())
				{
					// if the current frontier size is larger than the maximum size of the frontier before this point...
					if (frontier.size() >= max_nodes_generated)
						// update this maximum value
						max_nodes_generated = frontier.size();

					CurrentNode = get_next_node(frontier);
					frontier.pop();

					if (CurrentNode == Goal)
					{
						std::cout << "Goal node found.\nIterative deepening tree search complete.\nGenerating solution...\n";
						show_solution(CurrentNode);
						show_performance(num_nodes_generated, max_nodes_generated);
						// stop the search
						return;
					}
					// if the depth of the current node is not equal to the depth limit...
					if (CurrentNode.get_depth() < depth_limit)
					{
						// allow its child nodes to be generated and added to the frontier
						CurrentNode.expand();
						num_nodes_generated += push_children(frontier, CurrentNode.get_children());
					}
				}
				std::cout << "No solution found. Increasing the depth limit... \n";
				// increase the depth of the tree to explore if the goal node was not found by the current iteration of depth-limited search
				depth_limit++;
			}
		}

		// A* tree search
		void a_star_search(const Node& Root, const Node& Goal)
		{
			// nodes stored on the frontier are ordered based on the quality of their admissable heuristic to the goal node
			std::priority_queue<Node, std::vector<Node>, HeuristicComparator> frontier;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting A* tree search... \n";
			Node CurrentNode(Root);
			CurrentNode.set_heuristic_cost(Goal);
			frontier.push(CurrentNode);
			num_nodes_generated++;

			while (!frontier.empty())
			{
				// if the current frontier size is larger than the maximum size of the frontier before this point...
				if (frontier.size() >= max_nodes_generated)
					// update this maximum value
					max_nodes_generated = frontier.size();
		
				CurrentNode = get_next_node(frontier);
				frontier.pop();

				if (CurrentNode == Goal)
				{
					std::cout << "Goal node found.\nA* tree search complete.\nGenerating solution...\n";
					show_solution(CurrentNode);
					show_performance(num_nodes_generated, max_nodes_generated);
					// stop the search
					return;
				}

				CurrentNode.expand();
				// calculate the heuristic of each child node before adding them to the frontier
				// without this step child nodes will be incorrectly ordered within the priority queue
				for (std::vector<Node>::const_iterator it = begin(CurrentNode.get_children()); it != end(CurrentNode.get_children()); ++it)
				{
					it->set_heuristic_cost(Goal);
				}
				num_nodes_generated += push_children(frontier, CurrentNode.get_children());
			}
			std::cout << "No solution found.\n";
		}
	}

	/* ========== End Tree Search Functions ========== */

	void show_solution(Node CurrentNode)
	{
		// display the state of all node from the current node to the root node up the search tree 
		while (CurrentNode.get_parent() != nullptr)
		{
			CurrentNode.get_state().show();
			CurrentNode = *CurrentNode.get_parent();
		}
		CurrentNode.get_state().show();
	}

	void show_performance(uint time_complexity, uint space_complexity)
	{
		std::cout << "=================================\n";
		std::cout << "Time Complexity:\t" << time_complexity << "\n";
		std::cout << "Space Complexity:\t" << space_complexity << "\n";
		std::cout << "=================================\n";
	}
}