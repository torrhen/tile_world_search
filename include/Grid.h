#ifndef GRID_H
#define GRID_H

#include <array>
#include <utility>
#include <cstddef>

namespace TileSearch
{
	// store x, y positions and id of each grid tile
	struct tile 
	{
		std::pair<int, int> position = std::make_pair(0, 0);
		char ID = ' ';
	};

	class Grid
	{
		private:
			// size of grid set at compile time
			static constexpr std::size_t width = 4;
			static constexpr std::size_t height = 4;

			std::array<std::array<char, height>, width> configuration;

			tile P, A, B, C;
			
			// remove tiles from grid
			void clear();
			// add tiles to grid
			void build();

		public:
			Grid(tile P, tile A, tile B, tile C);

			// display grid configuration
			void show() const;

			// move the P tile within the grid
			void movePUp();
			void movePDown();
			void movePLeft();
			void movePRight();

			// return the position of a grid tile
			int getXPosition(const tile &grid_tile) const;
			int getYPosition(const tile &grid_tile) const;
			// return the ID of a grid tile
			char getID(const tile &grid_tile) const;

			// return the configuration of the grid
			const std::array<std::array<char, height>, width>& getConfiguration() const;
	};

	// two grids are identical if they have the exact same configuration
	bool operator==(const Grid &lhs, const Grid &rhs);
}

#endif
