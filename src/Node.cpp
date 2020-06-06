#include "../lib/Node.h"

#include <memory>

// constructor without parent node
Node::Node(const Board& State)
{
	this->depth = 0;
	this->State = State;
	this->Parent = nullptr;
}

// constructor with parent node
Node::Node(const Board& State, const Node& Parent)
{
	this->depth = Parent.getDepth() + 1;
	this->State = State;
	this->Parent = std::make_shared<Node>(Parent);
}

// copy constructor
Node::Node(const Node& Node)
{
	depth = Node.getDepth();
	State = Node.getState();
	Parent = Node.getParent();
}

// copy assignment operator
Node& Node::operator=(const Node& Node)
{
	depth = Node.getDepth();
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
std::shared_ptr<Node> Node::getParent() const
{
	return Parent;
}

// get depth
int getDepth() const
{
	return depth;
}