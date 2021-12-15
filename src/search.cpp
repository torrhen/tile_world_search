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
		Node::total_nodes_generated = 0;
		Node::max_nodes_generated = 0;

		if (type == Structure::TREE)
			std::cout << "[START]\t\tBreadth-first tree search\n";
		if (type == Structure::GRAPH)
			std::cout << "[START]\t\tBreadth-first graph search\n";

		Node CurrentNode(Root);
		frontier.push(CurrentNode);
		Node::total_nodes_generated++;

		while (!frontier.empty() && (Node::total_nodes_generated < node_limit && Node::max_nodes_generated < node_limit))
		{
			if (Node::total_nodes_generated % 1000 == 0)
			{
				std::cout << "[SEARCHING]\t...\r";
			}

			// if the current frontier size is larger than the maximum size of the frontier before this point...
			if (frontier.size() >= Node::max_nodes_generated)
				// update this maximum value
				Node::max_nodes_generated = frontier.size();

			CurrentNode = frontier.front();
			frontier.pop();

			if (CurrentNode == Goal)
			{
				std::cout << "\n[SUCCESS]\tGoal node found\n";
				std::cout << "[SOLUTION]\tSolution generated\n";
				
				show_solution(CurrentNode);
				// show performance
				std::cout << "[RESULTS]\tTime complexity:\t" << Node::total_nodes_generated << 
					"\n\t\tSpace complexity:\t" << Node::max_nodes_generated << "\n\n";
				// stop the search
				return;
			}

			if (type == Structure::TREE)
			{
				CurrentNode.expand();
				// add the children of the current node to the frontier and update the total number of nodes generated
				Node::total_nodes_generated += push_children(frontier, CurrentNode.get_children());			
			}
			else if (type == Structure::GRAPH)
			{
				// expand the node if it has not already been visited by the search
				if (!has_been_expanded(expanded_nodes, CurrentNode))
				{
					CurrentNode.expand();
					// add the children of the current node to the frontier and update the total number of nodes generated
					Node::total_nodes_generated += push_children(frontier, CurrentNode.get_children());
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
		Node::total_nodes_generated = 0;
		Node::max_nodes_generated = 0;

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
			Node::total_nodes_generated++;

			while (!frontier.empty())
			{
				if (!(Node::total_nodes_generated < node_limit && Node::max_nodes_generated < node_limit))
				{
					std::cout << "[FAILURE]\tNo solution found\n";
					return;
				}

				// if the current frontier size is larger than the maximum size of the frontier before this point...
				if (frontier.size() >= Node::max_nodes_generated)
					// update this maximum value
					Node::max_nodes_generated = frontier.size();

				CurrentNode = frontier.top();
				frontier.pop();

				if (CurrentNode == Goal)
				{
					std::cout << "[SUCCESS]\tGoal node found\n";
					std::cout << "[SOLUTION]\tSolution generated\n";

					show_solution(CurrentNode);
					// show performance
					std::cout << "[RESULTS]\tTime complexity:\t" << Node::total_nodes_generated << 
						"\n\t\tSpace complexity:\t" << Node::max_nodes_generated << "\n\n";
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
						Node::total_nodes_generated += push_children(frontier, CurrentNode.get_children());						
					}
					else if (type == Structure::GRAPH)
					{
						if (!has_been_expanded(expanded_nodes, CurrentNode))
						{
							// allow its child nodes to be generated and added to the frontier
							CurrentNode.expand();
							// add the children of the current node to the frontier and update the total number of nodes generated
							Node::total_nodes_generated += push_children(frontier, CurrentNode.get_children());
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

	// used to order the nodes stored the priority queue used by A* search
	auto calculate_heuristic = [](const Node& Left, const Node& Right)
	{
		return (Left.get_path_cost() + Left.get_heuristic_cost()) >= (Right.get_path_cost() + Right.get_heuristic_cost());
	};

	// A* tree search
	void a_star_search(const Structure type, const Node& Root, const Node& Goal, Heuristic heuristic_method)
	{
		// already expanded nodes
		std::vector<Node> expanded_nodes;
		// nodes stored on the frontier are ordered based on the quality of their admissable heuristic to the goal node
		std::priority_queue<Node, std::vector<Node>, decltype(calculate_heuristic)> frontier(calculate_heuristic);
		Node::total_nodes_generated = 0;
		Node::max_nodes_generated = 0;

		if (type == Structure::TREE)
			std::cout << "[START]\t\tA* tree search\n";
		if (type == Structure::GRAPH)
			std::cout << "[START]\t\tA* graph search\n";

		Node CurrentNode(Root);
		
		if (heuristic_method == Heuristic::MISPLACED_TILES)
		{
			CurrentNode.set_heuristic_cost(Goal, misplaced_tiles);
		}
		if (heuristic_method == Heuristic::MANHATTAN_DISTANCE)
		{
			CurrentNode.set_heuristic_cost(Goal, manhattan_distance);
		}

		//CurrentNode.set_heuristic_cost(Goal, manhattan_distance);
		
		frontier.push(CurrentNode);
		Node::total_nodes_generated++;

		while (!frontier.empty() && (Node::total_nodes_generated < node_limit && Node::max_nodes_generated < node_limit))
		{
			if (Node::total_nodes_generated % 1000 == 0)
			{
				std::cout << "[SEARCHING]\t...\r";
			}

			// if the current frontier size is larger than the maximum size of the frontier before this point...
			if (frontier.size() >= Node::max_nodes_generated)
				// update this maximum value
				Node::max_nodes_generated = frontier.size();
	
			CurrentNode = frontier.top();
			frontier.pop();

			if (CurrentNode == Goal)
			{
				std::cout << "\n[SUCCESS]\tGoal node found\n";
				std::cout << "[SOLUTION]\tSolution generated\n";

				show_solution(CurrentNode);
				// show performance
				std::cout << "[RESULTS]\tTime complexity:\t" << Node::total_nodes_generated << 
					"\n\t\tSpace complexity:\t" << Node::max_nodes_generated << "\n\n";
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
					if (heuristic_method == Heuristic::MISPLACED_TILES)
					{
						it->set_heuristic_cost(Goal, misplaced_tiles);
					}
					if (heuristic_method == Heuristic::MANHATTAN_DISTANCE)
					{
						it->set_heuristic_cost(Goal, manhattan_distance);
					}
				}
				// add the children of the current node to the frontier and update the total number of nodes generated
				Node::total_nodes_generated += push_children(frontier, CurrentNode.get_children());				
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
						if (heuristic_method == Heuristic::MISPLACED_TILES)
						{
							it->set_heuristic_cost(Goal, misplaced_tiles);
						}
						if (heuristic_method == Heuristic::MANHATTAN_DISTANCE)
						{
							it->set_heuristic_cost(Goal, manhattan_distance);
						}
					}
					// add the children of the current node to the frontier and update the total number of nodes generated
					Node::total_nodes_generated += push_children(frontier, CurrentNode.get_children());
					// remember the current node
					expanded_nodes.push_back(CurrentNode);
				}				
			}
		}
		std::cout << "\n[FAILURE]\tNo solution found\n";
	}

	void show_solution(Node CurrentNode)
	{
		std::vector<Node> solution;
		// store the path from the current node to the root node up the search tree 
		while (CurrentNode.get_parent() != nullptr)
		{
			solution.push_back(CurrentNode);
			CurrentNode = *CurrentNode.get_parent();
		}
		// add the root node to the solution
		solution.push_back(CurrentNode);
		// display solution
		for (const Node& node : solution)
		{
			node.get_state().show();
		}
	}
}