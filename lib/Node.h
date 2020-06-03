#ifndef NODE_H
#define NODE_H

<<<<<<< HEAD
#include "Board.h"

class Node
{
	private:
		Board State;

	public:
		// constructors
		Node(const Board& State);

		// copy constructor
		Node(const Node& Node);
		// copy assignment operator
		Node& operator=(const Node& Node);

		// get node state
		Board getState() const;
};

#endif
