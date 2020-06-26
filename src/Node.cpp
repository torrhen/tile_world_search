#include "../include/Grid.h"
// #include "../include/Node.h"

#include <memory>
#include <vector>

namespace TileSearch
{
	// /* ============ Node Class =============== */

	// Node::Node(Grid& state, Node& parent, unsigned int depth)
	// 	: state(make_unique<Grid>(new Grid(state))), parent(make_shared<Node>(new Node(parent))), depth(depth)
	// {

	// }

	// // create all possible child nodes
	// void Node::createChildren()
	// {
	// 	// create a new child node by moving tile P in all legal directions
	// 	for (int i = 0; i < 4; ++i)
	// 	{
	// 		StandardNode Child(*this);
	// 		switch(i)
	// 		{
	// 			case 0:
	// 			Child.getState()->movePUp();
	// 			break;
	// 			case 1:
	// 			Child.getState()->movePLeft();
	// 			break;
	// 			case 2:
	// 			Child.getState()->movePDown();
	// 			break;
	// 			case 3:
	// 			Child.getState()->movePRight();
	// 			break;
	// 		}
	// 		// if the movement of the P tile was successful then the child node state is different from its parents 
	// 		if (!Child.getState() == getState())
	// 		{	
	// 			// keep the child
	// 			children.push_back(Child);
	// 		}
	// 	}
	// }

	// std::unique_ptr<Grid> Node::getState() const
	// {
	// 	return state;
	// }

	// std::shared_ptr<Node> Node::getParent() const
	// {
	// 	return parent;
	// }

	// std::vector<std::shared_ptr<Node>> Node::getChildren() const
	// {
	// 	return children;
	// }

	// unsigned int Node::getDepth() const
	// {
	// 	return depth;
	// }

	// /* ============ Root Node Class =============== */

	// RootNode::RootNode(const StartGrid& state)
	// 	: Node(state, nullptr, 0)
	// {

	// }

	// /* ============ Standard Node Class =============== */

	// StandardNode::StandardNode(const Node& parent)
	// 	: Node(parent.getState(), parent, parent.getDepth() + 1)
	// {

	// }

	// StandardNode::StandardNode(const StandardNode& other)
	// {
	// 	state = make_unique<Grid>(new StandardGrid(*other.getState()));
	// 	parent = make_shared<Node>(new StandardNode(*other.getParent()));
	// 	depth = other.getDepth() + 1;
	// 	children = other.getChildren();
	// }

	// StandardNode& operator=(const StandardNode& other)
	// {
	// 	state = make_unique<Grid>(new StandardGrid(*other.getState()));
	// 	parent = make_shared<Node>(new StandardNode(*other.getParent()));
	// 	depth = other.getDepth() + 1;
	// 	children = other.getChildren();
	// }
}