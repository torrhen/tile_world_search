#ifndef NODE_H
#define NODE_H

#include "Grid.h"

#include <memory>
#include <vector>

namespace TileSearch
{
	typedef unsigned int uint;

	class Node
	{
	private:
		Grid State;
		// multiple nodes can share the same parent
		std::shared_ptr<Node> parent;
		// store the depth of the node within the search tree
		uint depth;
		uint path_cost;
		uint mutable heuristic_cost;

		// store child nodes
		static constexpr uint max_children = 4;
		std::vector<Node> children;

	public:
		explicit Node(const Grid& State);

		// create and store all valid child nodes
		void expand();

		void set_heuristic_cost(const Node& Goal) const;

		const Grid& get_state() const { return State; }
		const Node* get_parent() const { return parent.get(); }
		const uint& get_depth() const { return depth; }
		const std::vector<Node>& get_children() const { return children; }
		const uint& get_heuristic_cost() const { return heuristic_cost; }
		const uint& get_path_cost() const { return path_cost; }
	};

	bool operator==(const Node& Left, const Node& Right);
}

#endif
