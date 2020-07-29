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
		// store child nodes
		std::vector<Node> children;

		static constexpr uint max_children = 4;

	public:
		explicit Node(const Grid& State);

		// create and store all valid child nodes
		void expand();

		const Grid& get_state() const { return State; }
		const Node* get_parent() const { return parent.get(); }
		const uint& get_depth() const { return depth; }
		const std::vector<Node>& get_children() const { return children; }
	};

	bool operator==(const Node& Left, const Node& Right);
}

#endif
