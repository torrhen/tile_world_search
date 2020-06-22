#include "../include/Grid.h"
#include "../include/Node.h"

#include <memory>
#include <vector>

// namespace TileSearch
// {
// 	unsigned int Node::getDepth() const
// 	{
// 		return depth;
// 	}

// 	std::unique_ptr<Grid> Node::getState() const
// 	{
// 		return state;
// 	}

// 	std::shared_ptr<Node> Node::getParent() const
// 	{
// 		return parent;
// 	}

// 	std::vector<std::shared_ptr<Node>> Node::getChildren() const
// 	{
// 		return children;
// 	}

// 	RootNode::RootNode()
// 		: Node::depth(0)
// 	{
// 		this->state = std::make_unique<Grid>(new StartGrid());
// 		parent = std::make_shared<Node>(nullptr);
// 	}

// 	StandardNode::StandardNode(const Node& other)
// 		: Node::depth(other.getDepth() + 1)
// 	{
// 		state = std::make_unique<Grid>(&StandardGrid(other.getState()));
// 		parent = std::make_shared<Node>(&other);
// 	}

// 	Node& operator=(const Node& other)
// 		: depth(other.getDepth() + 1)
// 	{
// 		state = std::make_shared<Grid>(&StandardNode(other.getState()));
// 		parent = std::make_shared<Node>(&other);

// 		return *this;
// 	}

// 	bool StandardNode::isValidChild(const Node& other)
// 	{
// 		if (&other == this or other.getState() == state)
// 		{
// 			return false;
// 		}
// 		return true;
// 	}

// 	// create all possible child nodes
// 	void Node::createChildren()
// 	{
// 		// create a new child node by moving tile P in all legal directions
// 		for (int i = 0; i < 4; ++i)
// 		{
// 			StandardNode Child(*this);
// 			auto childstate = Child.getState();
// 			switch(i)
// 			{
// 				case 0:
// 				childstate->movePUp();
// 				break;
// 				case 1:
// 				childstate->movePLeft();
// 				break;
// 				case 2:
// 				childstate->movePDown();
// 				break;
// 				case 3:
// 				childstate->movePRight();
// 				break;
// 			}
// 			// if the movement of the P tile was successful then the child node state is different from its parents 
// 			if (isValidChild(Child))
// 			{	
// 				// keep the child
// 				children.push_back(Child);
// 			}
// 		}
// 	}
// }