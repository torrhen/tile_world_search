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
	Node::Node(const Node& Other)
	{
		this->depth = Other.getDepth();
		this->State = Other.getState();
		this->Parent = Other.getParent();
		this->Children = Other.getChildren();
	}

	// copy assignment operator
	Node& Node::operator=(const Node& Other)
	{
		// self assignment check
		if (&Other != this)
		{
			this->depth = Other.getDepth();
			this->State = Other.getState();
			this->Parent = Other.getParent();
			this->Children = Other.getChildren();
		}
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
			// create child node from the parent
			Node Child(*this);
			switch(i)
			{
				case 0:
				Child.State.movePUp();
				break;

				case 1:
				Child.State.movePLeft();
				break;

				case 2:
				Child.State.movePDown();
				break;

				case 3:
				Child.State.movePRight();
				break;
			}
			// if the child state is different to the parent state...(successful move was made)
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