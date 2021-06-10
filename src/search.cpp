#include "grid.hpp"
#include "node.hpp"
#include "search.hpp"

#include <iostream>

namespace TileSearch
{

	constexpr int node_limit = 1000000;

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

			while (!frontier.empty() && max_nodes_generated < node_limit)
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
				// add the children of the current node to the frontier and update the total number of nodes generated
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

				while (!frontier.empty() && max_nodes_generated < node_limit)
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
						// add the children of the current node to the frontier and update the total number of nodes generated
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

			while (!frontier.empty() && max_nodes_generated < node_limit)
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
				for (auto it = CurrentNode.get_children().cbegin(); it != CurrentNode.get_children().cend(); ++it)
				{
					it->set_heuristic_cost(Goal);
				}
				// add the children of the current node to the frontier and update the total number of nodes generated
				num_nodes_generated += push_children(frontier, CurrentNode.get_children());
			}
			std::cout << "No solution found.\n";
		}
	}

	/* ========== End Tree Search Functions ========== */

	/* ========== Graph Search Functions ========== */

	namespace Graph
	{
		bool has_been_expanded(const std::vector<Node>& expanded_nodes, const Node& CurrentNode)
		{
			for (auto it = expanded_nodes.cbegin(); it != expanded_nodes.cend(); ++it)
			{
				// do not expand the current node if a shallower node with the same state has already been expanded
				if ((CurrentNode == *it) && (CurrentNode.get_depth() >= it->get_depth()))
					return true;
			}
			return false;
		}

		// breadth-first graph search
		void breadth_first_search(const Node& Root, const Node& Goal)
		{
			// already expanded nodes
			std::vector<Node> expanded_nodes;
			// nodes stored on the frontier are FIFO
			std::queue<Node> frontier;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting breadth first graph search... \n";
			Node CurrentNode(Root);
			frontier.push(CurrentNode);
			num_nodes_generated++;

			while (!frontier.empty() && max_nodes_generated < node_limit)
			{
				// if the current frontier size is larger than the maximum size of the frontier before this point...
				if (frontier.size() >= max_nodes_generated)
					// update this maximum value
					max_nodes_generated = frontier.size();

				CurrentNode = get_next_node(frontier);
				frontier.pop();

				if (CurrentNode == Goal)
				{
					std::cout << "Goal node found.\nBreadth first graph search complete.\nGenerating solution...\n";
					show_solution(CurrentNode);
					show_performance(num_nodes_generated, max_nodes_generated);
					// stop the search
					return;
				}
				// expand the node if it has not already been visited by the search
				if (!has_been_expanded(expanded_nodes, CurrentNode))
				{
					CurrentNode.expand();
					// add the children of the current node to the frontier and update the total number of nodes generated
					num_nodes_generated += push_children(frontier, CurrentNode.get_children());
					// remember the current node
					expanded_nodes.push_back(CurrentNode);			
				}
			}
			std::cout << "No solution found.\n";
		}

		// iterative deepening graph search
		void iterative_deepening_search(const Node& Root, const Node& Goal)
		{
			// store the current depth limit of search
			uint depth_limit = 0;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting iterative deepening tree search... \n";
			while (true)
			{
				// already expanded nodes
				std::vector<Node> expanded_nodes;
				// nodes stored on the frontier are LIFO
				std::stack<Node> frontier;
				// start a new iteration of depth-limited tree search
				std::cout << "Starting depth limited graph search... \t(depth limit: " << depth_limit << ")\n";
				Node CurrentNode(Root);
				frontier.push(CurrentNode);
				num_nodes_generated++;

				while (!frontier.empty() && max_nodes_generated < node_limit)
				{
					// if the current frontier size is larger than the maximum size of the frontier before this point...
					if (frontier.size() >= max_nodes_generated)
						// update this maximum value
						max_nodes_generated = frontier.size();

					CurrentNode = get_next_node(frontier);
					frontier.pop();

					if (CurrentNode == Goal)
					{
						std::cout << "Goal node found.\nIterative deepening graph search complete.\nGenerating solution...\n";
						show_solution(CurrentNode);
						show_performance(num_nodes_generated, max_nodes_generated);
						// stop the search
						return;
					}
					// if the depth of the current node is not equal to the depth limit...
					// expand the node if it has not already been visited by the search
					if ((CurrentNode.get_depth() < depth_limit) && (!has_been_expanded(expanded_nodes, CurrentNode)))
					{
						// allow its child nodes to be generated and added to the frontier
						CurrentNode.expand();
						// add the children of the current node to the frontier and update the total number of nodes generated
						num_nodes_generated += push_children(frontier, CurrentNode.get_children());
						// remember the current node
						expanded_nodes.push_back(CurrentNode);
					}
				}
				std::cout << "No solution found. Increasing the depth limit... \n";
				// increase the depth of the tree to explore if the goal node was not found by the current iteration of depth-limited search
				depth_limit++;
			}
		}

		// A* graph search
		void a_star_search(const Node& Root, const Node& Goal)
		{
			std::vector<Node> expanded_nodes;
			// nodes stored on the frontier are ordered based on the quality of their admissable heuristic to the goal node
			std::priority_queue<Node, std::vector<Node>, HeuristicComparator> frontier;
			uint num_nodes_generated = 0;
			uint max_nodes_generated = 0;

			std::cout << "Starting A* graph search... \n";
			Node CurrentNode(Root);
			CurrentNode.set_heuristic_cost(Goal);
			frontier.push(CurrentNode);
			num_nodes_generated++;

			while (!frontier.empty() && max_nodes_generated < node_limit)
			{
				// if the current frontier size is larger than the maximum size of the frontier before this point...
				if (frontier.size() >= max_nodes_generated)
					// update this maximum value
					max_nodes_generated = frontier.size();
		
				CurrentNode = get_next_node(frontier);
				frontier.pop();

				if (CurrentNode == Goal)
				{
					std::cout << "Goal node found.\nA* graph search complete.\nGenerating solution...\n";
					show_solution(CurrentNode);
					show_performance(num_nodes_generated, max_nodes_generated);
					// stop the search
					return;
				}
				// expand the node if it has not already been visited by the search
				if (!has_been_expanded(expanded_nodes, CurrentNode))
				{
					CurrentNode.expand();
					// calculate the heuristic of each child node before adding them to the frontier
					// without this step child nodes will be incorrectly ordered within the priority queue
					for (auto it = CurrentNode.get_children().cbegin(); it != CurrentNode.get_children().cend(); ++it)
					{
						it->set_heuristic_cost(Goal);
					}
					// add the children of the current node to the frontier and update the total number of nodes generated
					num_nodes_generated += push_children(frontier, CurrentNode.get_children());
					// remember the current node
					expanded_nodes.push_back(CurrentNode);
				}
			}
			std::cout << "No solution found.\n";
		}
	}

	/* ========== End Graph Search Functions ========== */

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

	const Node& get_next_node(const std::queue<Node>& frontier) { return frontier.front(); }
	const Node& get_next_node(const std::stack<Node>& frontier) { return frontier.top(); }
	const Node& get_next_node(const std::priority_queue<Node, std::vector<Node>, HeuristicComparator>& frontier) { return frontier.top(); }
}