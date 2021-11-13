#include "grid.hpp"
#include "node.hpp"
#include "search.hpp"

#include <iostream>
#include <cstdint>

namespace tile_world_search
{
	// the search is stopped if either the time complexity or space complexity exceeds the node limit
	constexpr std::uint32_t node_limit = 1000000;

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

	// breadth-first tree search
	void breadth_first_search(const Structure type, const Node& Root, const Node& Goal)
	{
		// already expanded nodes
		std::vector<Node> expanded_nodes;
		// nodes stored on the frontier are FIFO
		std::queue<Node> frontier;
		std::uint32_t num_nodes_generated = 0;
		std::uint32_t max_nodes_generated = 0;

		if (type == Structure::TREE)
			std::cout << "[START]\t\tBreadth-first tree search\n";
		if (type == Structure::GRAPH)
			std::cout << "[START]\t\tBreadth-first graph search\n";

		Node CurrentNode(Root);
		frontier.push(CurrentNode);
		num_nodes_generated++;

		while (!frontier.empty() && (num_nodes_generated < node_limit && max_nodes_generated < node_limit))
		{
			if (num_nodes_generated % 1000 == 0)
			{
				std::cout << "[SEARCHING]\t...\r";
			}

			// if the current frontier size is larger than the maximum size of the frontier before this point...
			if (frontier.size() >= max_nodes_generated)
				// update this maximum value
				max_nodes_generated = frontier.size();

			CurrentNode = get_next_node(frontier);
			frontier.pop();

			if (CurrentNode == Goal)
			{
				std::cout << "\n[SUCCESS]\tGoal node found\n";
				std::cout << "[SOLUTION]\tSolution generated\n";
				
				show_solution(CurrentNode);
				// show performance
				std::cout << "[RESULTS]\tTime complexity:\t" << num_nodes_generated << 
					"\n\t\tSpace complexity:\t" << max_nodes_generated << "\n\n";
				// stop the search
				return;
			}

			if (type == Structure::TREE)
			{
				CurrentNode.expand();
				// add the children of the current node to the frontier and update the total number of nodes generated
				num_nodes_generated += push_children(frontier, CurrentNode.get_children());			
			}
			else if (type == Structure::GRAPH)
			{
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
		}
		std::cout << "\n[FAILURE]\tNo solution found\n";
	}

	// iterative deepening tree search
	void iterative_deepening_search(const Structure type, const Node& Root, const Node& Goal)
	{
		// store the current depth limit of search
		std::uint32_t depth_limit = 0;
		std::uint32_t num_nodes_generated = 0;
		std::uint32_t max_nodes_generated = 0;

		if (type == Structure::TREE)
			std::cout << "[START]\t\tIterative deepening tree search\n";
		if (type == Structure::GRAPH)
			std::cout << "[START]\t\tIterative deepening graph search\n";

		while (true)
		{
			// already expanded nodes
			std::vector<Node> expanded_nodes;
			// nodes stored on the frontier are LIFO
			std::stack<Node> frontier;
			// start a new iteration of depth-limited tree search
			std::cout << "[DEPTH LIMIT]\tIncreasing the depth limit to " << depth_limit << std::endl;
			std::cout << "[SEARCHING]\t...\n";

			Node CurrentNode(Root);
			frontier.push(CurrentNode);
			num_nodes_generated++;

			while (!frontier.empty())
			{
				if (!(num_nodes_generated < node_limit && max_nodes_generated < node_limit))
				{
					std::cout << "[FAILURE]\tNo solution found\n";
					return;
				}

				// if the current frontier size is larger than the maximum size of the frontier before this point...
				if (frontier.size() >= max_nodes_generated)
					// update this maximum value
					max_nodes_generated = frontier.size();

				CurrentNode = get_next_node(frontier);
				frontier.pop();

				if (CurrentNode == Goal)
				{
					std::cout << "[SUCCESS]\tGoal node found\n";
					std::cout << "[SOLUTION]\tSolution generated\n";

					show_solution(CurrentNode);
					// show performance
					std::cout << "[RESULTS]\tTime complexity:\t" << num_nodes_generated << 
						"\n\t\tSpace complexity:\t" << max_nodes_generated << "\n\n";
					// stop the search
					return;
				}
				// if the depth of the current node is not equal to the depth limit...
				if (CurrentNode.get_depth() < depth_limit)
				{
					if (type == Structure::TREE)
					{
						// allow its child nodes to be generated and added to the frontier
						CurrentNode.expand();
						// add the children of the current node to the frontier and update the total number of nodes generated
						num_nodes_generated += push_children(frontier, CurrentNode.get_children());						
					}
					else if (type == Structure::GRAPH)
					{
						if (!has_been_expanded(expanded_nodes, CurrentNode))
						{
							// allow its child nodes to be generated and added to the frontier
							CurrentNode.expand();
							// add the children of the current node to the frontier and update the total number of nodes generated
							num_nodes_generated += push_children(frontier, CurrentNode.get_children());
							// remember the current node
							expanded_nodes.push_back(CurrentNode);						
						}
					}
				}
			}
			// increase the depth of the tree to explore if the goal node was not found by the current iteration of depth-limited search
			depth_limit++;
		}
	}

	// A* tree search
	void a_star_search(const Structure type, const Node& Root, const Node& Goal)
	{
		// already expanded nodes
		std::vector<Node> expanded_nodes;
		// nodes stored on the frontier are ordered based on the quality of their admissable heuristic to the goal node
		std::priority_queue<Node, std::vector<Node>, decltype(heuristic)> frontier(heuristic);
		std::uint32_t num_nodes_generated = 0;
		std::uint32_t max_nodes_generated = 0;

		if (type == Structure::TREE)
			std::cout << "[START]\t\tA* tree search\n";
		if (type == Structure::GRAPH)
			std::cout << "[START]\t\tA* graph search\n";

		Node CurrentNode(Root);
		CurrentNode.set_heuristic_cost(Goal);
		frontier.push(CurrentNode);
		num_nodes_generated++;

		while (!frontier.empty() && (num_nodes_generated < node_limit && max_nodes_generated < node_limit))
		{
			if (num_nodes_generated % 1000 == 0)
			{
				std::cout << "[SEARCHING]\t...\r";
			}

			// if the current frontier size is larger than the maximum size of the frontier before this point...
			if (frontier.size() >= max_nodes_generated)
				// update this maximum value
				max_nodes_generated = frontier.size();
	
			CurrentNode = get_next_node(frontier);
			frontier.pop();

			if (CurrentNode == Goal)
			{
				std::cout << "\n[SUCCESS]\tGoal node found\n";
				std::cout << "[SOLUTION]\tSolution generated\n";

				show_solution(CurrentNode);
				// show performance
				std::cout << "[RESULTS]\tTime complexity:\t" << num_nodes_generated << 
					"\n\t\tSpace complexity:\t" << max_nodes_generated << "\n\n";
				// stop the search
				return;
			}

			if (type == Structure::TREE)
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
			}
			else if (type == Structure::GRAPH)
			{
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
		}
		std::cout << "\n[FAILURE]\tNo solution found\n";
	}

	const Node& get_next_node(const std::queue<Node>& frontier) { return frontier.front(); }
	const Node& get_next_node(const std::stack<Node>& frontier) { return frontier.top(); }
	const Node& get_next_node(const std::priority_queue<Node, std::vector<Node>, decltype(heuristic)>& frontier) { return frontier.top(); }

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
}