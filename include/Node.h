#ifndef NODE_H
#define NODE_H

#include "Grid.h"

#include <memory>
#include <vector>

namespace TileSearch
{
	class Node
	{
	private:
		Grid state;
		// multiple nodes can share the same parent
		std::shared_ptr<Node> parent;
		// store the depth of the node within the search tree
		unsigned int depth;
		// store child nodes
		std::vector<Node> children;

	public:
		Node(const Grid &state);

		void createChildren();

		// return node state
		const Grid& getState() const;
		// return pointer to parent
		const Node* getParent() const;
		// return depth of node
		const unsigned int& getDepth() const;
		// return child nodes 
		const std::vector<Node>& getChildren() const;
	};
}

#endif
