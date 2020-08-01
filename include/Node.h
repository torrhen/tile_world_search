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
		friend class HeuristicNode;

	protected:
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
		virtual ~Node() = default;

		// create and store all valid child nodes
		virtual void expand();

		const Grid& get_state() const { return State; }
		const Node* get_parent() const { return parent.get(); }
		const uint& get_depth() const { return depth; }
		const std::vector<Node>& get_children() const { return children; }
	};

	class HeuristicNode : public Node
	{
	private:
		uint heuristic_cost;
		uint path_cost;
		std::vector<HeuristicNode> children;

	public:
		explicit HeuristicNode(const Grid& State);
		~HeuristicNode() = default;

		void expand() override;

		const uint& get_heuristic_cost() const { return heuristic_cost; }
		const uint& get_path_cost() const { return path_cost; }
	};

	bool operator==(const Node& Left, const Node& Right);
}

#endif
