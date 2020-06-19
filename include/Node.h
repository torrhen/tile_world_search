#ifndef NODE_H
#define NODE_H

#include "Grid.h"

#include <memory>
#include <vector>

namespace TileSearch
{
	class Node
	{
		protected:
			int depth;
			Grid state;
			// multiple nodes can share the same parent node
			std::shared_ptr<Node> Parent;
			std::vector<Node> Children;

		public:
			Node() = delete;
			Node(const Grid& State);
			Node(const Node& other) = delete;
			~Node() = default;

			Node& operator=(const Node& other) = default;


			void createChildren();

			Grid getState() const;
			std::shared_ptr<Node> getParent() const;
			int getDepth() const;
			std::vector<Node> getChildren() const;
	};

	class RootNode : public Node
	{
		public:
			RootNode(const Grid& state);
			RootNode(const Node& other) = delete;
			~RootNode() = default;

			Node& operator=(const Node& other) = delete;

	};

	class GoalNode : public Node
	{
		public: 
			GoalNode(const Grid& state);
			GoalNode(const Node& other) = delete;
			~GoalNode() = default;

			Node& operator=(const Node& other) = delete;
	};

	class StandardNode : public Node
	{
		public:
			StandardNode() = delete;
			StandardNode(const Node& other);
			~StandardNode() = default;

			Node& operator=(const Node& other);
	};
}

#endif
