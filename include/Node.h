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
	private:
		Grid state;
		std::shared_ptr<Node> parent;
		std::size_t depth;
		std::vector<Node> children;
	
	public:
		Node(const Grid &state);

		void generateChildren();

		Grid getState() const;
		Node* getParent() const;
		std::size_t getDepth() const;
		std::vector<Node> getChildren() const;
	};
}

#endif
