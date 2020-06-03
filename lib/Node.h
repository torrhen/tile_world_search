#ifndef NODE_H
#define NODE_H

#include "Board.h"

class Node
{
	private:
		Board State;
		Node* Parent;

	public:
		// constructors
		Node(const Board& State);

		// copy constructor
		Node(const Node& Node);
		// copy assignment operator
		Node& operator=(const Node& Node);
		// destructor
		~Node();

		// get node state
		Board getState() const;

		// get Parent 
		Node getParent() const;
};

#endif
