#ifndef NODE_H
#define NODE_H

#include "Grid.h"

#include <cstddef>
#include <memory>
#include <vector>

namespace TileSearch
{
	class Node
	{
		protected:
			// pointer to grid state contained within node
			std::unique_ptr<Grid> state;
			// pointer to node parent
			std::shared_ptr<Node> parent;
			// collection of child nodes
			std::vector<std::shared_ptr<Node>> children;
			// depth of the node within the search tree
			unsigned int depth;

			Node(Grid& state, Node& parent, unsigned int depth);

		public:
			// generate all available, legal child nodes of the current node
			void createChildren();

			unsigned int getDepth() const;
			std::unique_ptr<Grid> getState() const;
			std::shared_ptr<Node> getParent() const;
			std::vector<std::shared_ptr<Node>> getChildren() const;
	};

	class RootNode : public Node
	{
		public:
			RootNode(const StartGrid& state);

			RootNode(const RootNode& other) = delete;
			RootNode(RootNode&& other) = delete;

			RootNode& operator=(const RootNode& other) = delete;
			RootNode& operator=(RootNode&& other) = delete;
	};

	class StandardNode : public Node
	{
		public:
			StandardNode() = delete;
			StandardNode(const Node& parent);

			StandardNode(const StandardNode& other);
			// StandardNode(StandardNode&& other) = delete;
			StandardNode& operator=(const StandardNode& other);
			// StandardNode& operator=(StandardNode&& other) = delete;
	};
}

#endif
