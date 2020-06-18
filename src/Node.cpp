#include "../include/Node.h"

#include <memory>
#include <vector>

namespace TileSearch
{
	// // constructor without parent node (root node)
	// Node::Node(const Grid& state)
	// {
	// 	this->depth = 0;
	// 	this->State = state;
	// 	this->Parent = nullptr;
	// }

	// Node::Node(const Node& other)
	// {
	// 	this->depth = other.getDepth();
	// 	this->State = other.getState();
	// 	this->Parent = other.getParent();
	// 	this->Children = other.getChildren();
	// }

	// Node& Node::operator=(const Node& other)
	// {
	// 	// self assignment check
	// 	if (&other != this)
	// 	{
	// 		this->depth = other.getDepth();
	// 		this->State = other.getState();
	// 		this->Parent = other.getParent();
	// 		this->Children = other.getChildren();
	// 	}
	// 	return *this;
	// }

	// Node::~Node()
	// {
	
	// }

	// // create all possible child nodes
	// void Node::createChildren()
	// {
	// 	// create a new child node by moving tile P in each direction
	// 	for (int i = 0; i < 4; ++i)
	// 	{
	// 		Node Child(*this);
	// 		switch(i)
	// 		{
	// 			case 0:
	// 			Child.State.movePUp();
	// 			break;

	// 			case 1:
	// 			Child.State.movePLeft();
	// 			break;

	// 			case 2:
	// 			Child.State.movePDown();
	// 			break;

	// 			case 3:
	// 			Child.State.movePRight();
	// 			break;
	// 		}
	// 		// if the movement of the P tile was successful then the child node state is different from its parents 
	// 		if (!(Child.State.isIdenticalTo(this->getState())))
	// 		{	
	// 			// update child node
	// 			Child.Parent.reset(this);
	// 			Child.depth += 1;
	// 			Child.Children.clear();

	// 			// keep the child
	// 			Children.push_back(Child);
	// 		}
	// 	}
	// }

	// Grid Node::getState() const
	// {
	// 	return State;
	// }

	// std::shared_ptr<Node> Node::getParent() const
	// {
	// 	return Parent;
	// }

	// int Node::getDepth() const
	// {
	// 	return depth;
	// }

	// std::vector<Node> Node::getChildren() const
	// {
	// 	return Children;
	// }
}