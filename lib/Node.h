#ifndef NODE_H
#define NODE_H

#include "Board.h"

#include <memory>

class Node
{
	private:
		Board State;
		std::shared_ptr<Node> Parent;

	public:
		// constructors
		Node(const Board& State);
		Node(const Board& State, const Node& Parent);

		// copy constructor
		Node(const Node& Node);
		// copy assignment operator
		Node& operator=(const Node& Node);
		// destructor
		~Node();

		// get node state
		Board getState() const;

		// get Parent 
		std::shared_ptr<Node> getParent() const;
};

#endif
