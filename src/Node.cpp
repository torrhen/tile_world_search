#include "../lib/Node.h"

// constructor
Node::Node(const Board& State)
{
	this->State = State;
}

// copy constructor
Node::Node(const Node& Node)
{
	State = Node.getState();
}

// copy assignment operator
Node& Node::operator=(const Node& Node)
{
	State = Node.getState();
	return *this;
}

// get state
Board Node::getState() const
{
	return State;
}