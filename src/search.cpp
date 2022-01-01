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

		// set the root node as the current node and add to the frontier
		Node CurrentNode(Root);
		frontier.push(std::move(CurrentNode));
		Node::total_nodes_generated++;

		// search until the frontier is empty or the node limit is exceeded
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

			// get the current node from the frontier
			CurrentNode = frontier.front();
			frontier.pop();
			// check if the current node is the goal node
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
				// generate the child nodes
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
					expanded_nodes.push_back(std::move(CurrentNode));			
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

			// set the root node as the current node and add to the frontier
			Node CurrentNode(Root);
			frontier.push(CurrentNode);
			Node::total_nodes_generated++;

			// search until the frontier is empty
			while (!frontier.empty())
			{
				// stop the search if the node limit is exceeded
				if (!(Node::total_nodes_generated < node_limit && Node::max_nodes_generated < node_limit))
				{
					std::cout << "[FAILURE]\tNo solution found\n";
					return;
				}
				// if the current frontier size is larger than the maximum size of the frontier before this point...
				if (frontier.size() >= Node::max_nodes_generated)
					// update this maximum value
					Node::max_nodes_generated = frontier.size();

				// get the current node from the frontier
				CurrentNode = frontier.top();
				frontier.pop();
				// check if the current node is the goal node
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
						// generate child nodes
						CurrentNode.expand();
						// add the children of the current node to the frontier and update the total number of nodes generated
						Node::total_nodes_generated += push_children(frontier, CurrentNode.get_children());						
					}
					else if (type == Structure::GRAPH)
					{
						// expand the node if it has not already been visited by the search
						if (!has_been_expanded(expanded_nodes, CurrentNode))
						{
							// generate child nodes
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

	// A* tree search
	void a_star_search(const Structure type, const Node& Root, const Node& Goal, Heuristic heuristic_method)
	{
		// already expanded nodes
		std::vector<Node> expanded_nodes;
		// used to order the nodes to expand by A* search
		auto lower_heuristic_cost = [](const Node& Left, const Node& Right)
		{
			return (Left.get_path_cost() + Left.get_heuristic_cost()) >= (Right.get_path_cost() + Right.get_heuristic_cost());
		};
		// prioritise nodes with the lowest heuristic cost to the goal node
		std::priority_queue<Node, std::vector<Node>, decltype(lower_heuristic_cost)> frontier(lower_heuristic_cost);
		Node::total_nodes_generated = 0;
		Node::max_nodes_generated = 0;

		if (type == Structure::TREE)
			std::cout << "[START]\t\tA* tree search\n";
		if (type == Structure::GRAPH)
			std::cout << "[START]\t\tA* graph search\n";

		// set the root node as the current node, set the heuristic cost and add to the frontier
		Node CurrentNode(Root);
		if (heuristic_method == Heuristic::MISPLACED_TILES)
		{
			CurrentNode.set_heuristic_cost(Goal, misplaced_tiles);
		}
		if (heuristic_method == Heuristic::MANHATTAN_DISTANCE)
		{
			CurrentNode.set_heuristic_cost(Goal, manhattan_distance);
		}
		frontier.push(CurrentNode);
		Node::total_nodes_generated++;

		// search until the frontier is empty or until the node limit is exceeded
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
	
			// get the current node from the frontier
			CurrentNode = frontier.top();
			frontier.pop();
			// check if the current node is the goal node
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
				// generate child nodes			
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
					// generate child nodes
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