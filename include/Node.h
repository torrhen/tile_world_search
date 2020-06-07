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
			// store depth of the node within the search tree
			int depth;
			// store the current node state
			Grid State;
			// store the parent node (multiple nodes can share the same parent)
			std::shared_ptr<Node> Parent;
			// store node children
			std::vector<Node> Children;

		public:
			// constructors
			Node(const Grid& State);
			Node(const Grid& State, const Node& Parent);

			// copy constructor
			Node(const Node& Node);
			// copy assignment operator
			Node& operator=(const Node& Node);
			// destructor
			~Node();

			// create children
			void createChildren();

			// get node state
			Grid getState() const;

			// get Parent 
			std::shared_ptr<Node> getParent() const;

			// get node depth
			int getDepth() const;

			// get children
			std::vector<Node> getChildren() const;
	};
}

#endif
