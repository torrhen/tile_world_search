#ifndef NODE_H
#define NODE_H

#include "Board.h"

class Node
{
	private:
		Board* State;

	public:
		// constructor
		Node();
		// copy constructor
		Node(const Node& Node);
		// copy assignment operator
		Node& operator=(const Node& Node);

		// get node state
		Board getState() const;
},

#endif
