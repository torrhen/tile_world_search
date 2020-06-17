#ifndef GRID_H
#define GRID_H

#include <array>
#include <cstddef>

namespace TileSearch
{
	struct Tile
	{
		int x, y;
		char id;
	};

	class Grid
	{
		private:
			// store the desired final positions of each tile in the grid
			static constexpr Tile P_goal = {3, 0, 'P'};
			static constexpr Tile A_goal = {1, 2, 'A'};
			static constexpr Tile B_goal = {1, 1, 'B'};
			static constexpr Tile C_goal = {1, 0, 'C'};

			// size of grid set at compile time
			static constexpr std::size_t width = 4;
			static constexpr std::size_t height = 4;
			
			std::array<std::array<char, height>, width> configuration;

			// store the current positions of each grid tile
			Tile P;
			Tile A;
			Tile B;
			Tile C;

			// empty grids cannot be displayed to the console
			bool isEmpty = false;

		public:

			Grid();

			Grid(const Grid& other);
			Grid& operator=(const Grid& other);

			Grid(Grid&& other);
			Grid& operator=(Grid&& other);

			~Grid();

			// remove grid tiles
			void clear();

			// place grid tiles
			void build();

			// move the P tile
			void movePUp() noexcept;
			void movePDown() noexcept;
			void movePLeft() noexcept;
			void movePRight() noexcept;

			// display grid configuration
			void show();

			// check if two grids have the same configuration
			bool isIdenticalTo(const Grid& other);

			// check if goal grid has been reached
			bool isGoal();
	};
}

#endif
