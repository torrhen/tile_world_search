#include "../lib/Node.h"

// constructor
Node::Node()
{
	State = &(Board());
}

// copy constructor
Node::Node(const Node& Node)
{
	State = Node.State;
}

// copy assignment operator
Node& Node::operator=(const Node& Node)
{
	State = Node.State;
	return *this;
}

// get state
Board Node::getState() const
{
	return *State;
}