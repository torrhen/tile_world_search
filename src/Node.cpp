#include "../lib/Node.h"

#include <memory>

// constructors
Node::Node(const Board& State)
{
	this->State = State;
	this->Parent = std::shared_ptr<Node>(nullptr);
}

Node::Node(const Board& State, Node* Parent)
{
	this->State = State;
	this->Parent = std::shared_ptr<Node>(Parent);
}

// copy constructor
Node::Node(const Node& Node)
{
	State = Node.getState();
	Parent = Node.getParent();
}

// copy assignment operator
Node& Node::operator=(const Node& Node)
{
	State = Node.getState();
	Parent = Node.getParent();
	return *this;
}

// destructor
Node::~Node()
{
	
}

// get state
Board Node::getState() const
{
	return State;
}

// get Parent
Node* Board::getParent() const
{
	return Parent;
}