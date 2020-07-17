#ifndef TREE_SEARCH_H
#define TREE_SEARCH_H

#include "Grid.h"
#include "Node.h"

#include <vector>
#include <queue>
#include <random>
#include <algorithm>

namespace TileSearch
{	
	template<typename T>
	class TreeSearch
	{
	protected:
		// store the root node
		Node root;
		// store the goal node
		Node goal;
		// store the time complexity
		unsigned int total_nodes;
		// store the space complexity
		unsigned int max_nodes;

		T frontier;
		std::vector<Node> solution;

		TreeSearch(const Node& root, const Node& goal);

		virtual ~TreeSearch() = default;

		void expand(Node& node);
		void generateSolution(Node node);
		void setup();
		void updateSpaceComplexity();

		// run the search
		virtual int run() = 0;


	public:
		// delete copy constructors/assignments
		TreeSearch(const TreeSearch&) = delete;
		TreeSearch& operator=(const TreeSearch&) = delete;

		// delete move constructors/assignments
		TreeSearch(TreeSearch&&) = delete;
		TreeSearch& operator=(TreeSearch&&) = delete;

		void displaySolution() const;
		const unsigned int& getTimeComplexity() const;
		const unsigned int& getSpaceComplexity() const;
	};

	class BreadthFirstTreeSearch : public TreeSearch<std::queue<Node>>
	{
	public:
		BreadthFirstTreeSearch(const Node& root, const Node& goal);

		// delete copy constructors/assignments
		BreadthFirstTreeSearch(const BreadthFirstTreeSearch&) = delete;
		BreadthFirstTreeSearch& operator=(const BreadthFirstTreeSearch&) = delete;

		// delete move constructors/assignments
		BreadthFirstTreeSearch(BreadthFirstTreeSearch&&) = delete;
		BreadthFirstTreeSearch& operator=(BreadthFirstTreeSearch&&) = delete;

		~BreadthFirstTreeSearch() = default;

		int run();
	};
}

#endif