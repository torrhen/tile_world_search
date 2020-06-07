#include "../lib/Node.h"

#include <memory>

namespace TileSearch
{
	// constructor without parent node (root node)
	Node::Node(const Grid& State)
	{
		this->depth = 0;
		this->State = State;
		this->Parent = nullptr;
	}

	// constructor with parent node (child node)
	Node::Node(const Grid& State, const Node& Parent)
	{
		this->depth = Parent.getDepth() + 1;
		this->State = State;
		this->Parent = std::make_shared<Node>(Parent);
	}

	// copy constructor
	Node::Node(const Node& Node)
	{
		this->depth = Node.getDepth();
		this->State = Node.getState();
		this->Parent = Node.getParent();
	}

	// copy assignment operator
	Node& Node::operator=(const Node& Node)
	{
		this->depth = Node.getDepth();
		this->State = Node.getState();
		this->Parent = Node.getParent();
		return *this;
	}

	// destructor
	Node::~Node()
	{
	
	}

	// get node state
	Grid Node::getState() const
	{
		return State;
	}

	// get parent node
	std::shared_ptr<Node> Node::getParent() const
	{
		return Parent;
	}

	// get node depth
	int Node::getDepth() const
	{
		return depth;
	}
}