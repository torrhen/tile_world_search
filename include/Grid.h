#ifndef GRID_H
#define GRID_H

#include <array>
#include <utility>
#include <cstddef>

namespace TileSearch
{
	// store x, y positions of each grid tile
	using tile = std::pair<int, int>;

	class Grid
	{
		private:
			// size of grid set at compile time
			static constexpr std::size_t width = 4;
			static constexpr std::size_t height = 4;

			std::array<std::array<char, height>, width> configuration;

			tile P;
			tile A;
			tile B;
			tile C;

			// remove tiles from grid
			void clear();
			// add tiles to grid
			void build();
			
		public:
			Grid(tile P, tile A, tile B, tile C);

			// display grid configuration
			void show();

			// move the P tile within the grid
			void movePUp();
			void movePDown();
			void movePLeft();
			void movePRight();

			// return the positions of grid tiles
			int getXPosition(tile grid_tile) const;
			int getYPosition(tile grid_tile) const;

			// return the configuration of the grid
			std::array<std::array<char, height>, width> getConfiguration() const;
	};

	// two grids are identical if they have the exact same configuration
	bool operator==(const Grid &first, const Grid &second);
}

#endif
