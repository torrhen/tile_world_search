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
			int depth;
			// store the current node state
			Grid State;
			// store the parent node (multiple nodes can share the same parent)
			std::shared_ptr<Node> Parent;
			// store node children
			std::vector<Node> Children;

		public:
			Node(const Grid& State);

			Node(const Node& Node);
			Node& operator=(const Node& Node);

			~Node();

			void createChildren();

			Grid getState() const;
			std::shared_ptr<Node> getParent() const;
			int getDepth() const;
			std::vector<Node> getChildren() const;
	};
}

#endif
