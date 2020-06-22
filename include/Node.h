#ifndef NODE_H
#define NODE_H

#include "Grid.h"

#include <cstddef>
#include <memory>
#include <vector>

// namespace TileSearch
// {
// 	class Node
// 	{
// 		protected:
// 			// depth of the node within the search tree
// 			unsigned int depth;
// 			// pointer to grid state contained within node
// 			std::unique_ptr<Grid> state;
// 			// pointer to node parent
// 			std::shared_ptr<Node> parent;
// 			// collection of child nodes
// 			std::vector<std::shared_ptr<Node>> children;

// 			Node(const Node& other) = default;
// 			// Node(Node&& other) = delete;
// 			Node& operator=(const Node& other) = default;
// 			// Node& operator=(Node&& other) = delete;

// 		public:
// 			// generate all available, legal child nodes of the current node
// 			void createChildren();

// 			unsigned int getDepth() const;
// 			std::unique_ptr<Grid> getState() const;
// 			std::shared_ptr<Node> getParent() const;
// 			std::vector<std::shared_ptr<Node>> getChildren() const;
// 	};

// 	class RootNode : public Node
// 	{
// 		public:
// 			RootNode();

// 			RootNode(const Node& other) = delete;
// 			RootNode(Node&& other) = delete;
// 			Node& operator=(const Node& other) = delete;
// 			Node& operator=(Node&& other) = delete;
// 	};

// 	class StandardNode : public Node
// 	{
// 		public:
// 			StandardNode() = delete;

// 			StandardNode(const Node& other);
// 			// StandardNode(Node&& other) = delete;
// 			Node& operator=(const Node& other);
// 			// Node& operator=(Node&& other) = delete;

// 			bool isValidChild(const Node& other);
// 	};
// }

#endif
