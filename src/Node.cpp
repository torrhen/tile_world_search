#include "../include/Node.h"

#include <memory>
#include <vector>

namespace TileSearch
{
	// constructor without parent node (root node)
	Node::Node(const Grid& State)
	{
		this->depth = 0;
		this->State = State;
		this->Parent = nullptr;
	}

	// copy constructor
	Node::Node(const Node& Node)
	{
		this->depth = Node.getDepth();
		this->State = Node.getState();
		this->Parent = Node.getParent();
		this->Children = Node.getChildren();
	}

	// copy assignment operator
	Node& Node::operator=(const Node& Node)
	{
		this->depth = Node.getDepth();
		this->State = Node.getState();
		this->Parent = Node.getParent();
		this->Children = Node.getChildren();
		return *this;
	}

	// destructor
	Node::~Node()
	{
	
	}

	// create node children
	void Node::createChildren()
	{
		for (int i = 0; i < 4; ++i)
		{
			Node Child(*this);
			switch(i)
			{
				case 0:
				Child.State.movePUp();
				break;

				case 1:
				Child.State.movePLeft();
				// check if child state is the same as parent state (no move made)
				break;

				case 2:
				Child.State.movePDown();
				// check if child state is the same as parent state (no move made)
				break;

				case 3:
				Child.State.movePRight();
				// check if child state is the same as parent state (no move made)
				break;
			}
			// if the child state is not equal to the parent state...
			if (!(Child.State.isIdenticalTo(this->getState())))
			{	
				// update child node
				Child.Parent.reset(this);
				Child.depth += 1;
				Child.Children.clear();

				// keep the child
				Children.push_back(Child);
			}
		}
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

	// get node children
	std::vector<Node> Node::getChildren() const
	{
		return Children;
	}
}