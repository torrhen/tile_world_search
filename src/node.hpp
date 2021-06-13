#ifndef NODE_H
#define NODE_H

#include "grid.hpp"

#include <memory>
#include <vector>
#include <cstdint>

namespace tile_world_search
{
	class Node
	{
	private:
		Grid State;
		// multiple tree nodes can share the same parent node
		std::shared_ptr<Node> parent;
		std::uint32_t depth;
		std::uint32_t path_cost;
		// the heuristic cost of a node is calculated by A* search separate from the instantiation of the class
		std::uint32_t mutable heuristic_cost;
		// the P tile can only move in four unique directions therefore only four children are possible for each node in the tree
		static constexpr std::uint32_t max_children = 4;
		std::vector<Node> children;

	public:
		explicit Node(const Grid& State);
		// create node children
		void expand();
		// calculate the estimated cost from the current node to the goal node (based on manhattan distance)
		void set_heuristic_cost(const Node& Goal) const;
		const Grid& get_state() const { return State; }
		Node* get_parent() const { return parent.get(); }
		std::uint32_t get_depth() const { return depth; }
		const std::vector<Node>& get_children() const { return children; }
		std::uint32_t get_heuristic_cost() const { return heuristic_cost; }
		std::uint32_t get_path_cost() const { return path_cost; }
	};
	// check if two nodes have identical states
	bool operator==(const Node& Left, const Node& Right);
}

#endif
