#ifndef GRID_H
#define GRID_H

#include <array>
#include <cstddef>

namespace TileSearch
{
	class Grid
	{
		private:
			// store grid structure
			const static std::size_t width = 4;
			const static std::size_t height = 4;
			// store grid
			std::array<std::array<char, width>, height> configuration;

			struct Tile
			{
				int x;
				int y;
				char id;
			};
			Tile P;
			Tile A;
			Tile B;
			Tile C;

			// does the grid contain tiles?
			bool isEmpty = false;

		public:
			Grid();
			// copy constructor
			Grid(const Grid& Grid);
			// copy assignment operator
			Grid& operator=(const Grid& Grid);
			// move constructor
			Grid(Grid&& Grid);
			// move assignment operator
			Grid& operator=(Grid&& Grid);
			~Grid();

			// remove all tiles from grid
			void clear();

			// add tiles to grid
			void build();

			// move the P tile
			void movePUp();
			void movePDown();
			void movePLeft();
			void movePRight();

			// display grid configuration
			void show();

			// check if two grids have the same configuration
			bool isIdenticalTo(const Grid& Other);
	};
}

#endif
