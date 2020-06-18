#ifndef GRID_H
#define GRID_H

#include <array>
#include <utility>
#include <cstddef>

namespace TileSearch
{
	class Grid
	{
		protected:
			// size of grid set at compile time
			static constexpr std::size_t grid_width = 4;
			static constexpr std::size_t grid_height = 4;

			std::array<std::array<char, grid_height>, grid_width> configuration;

			// store x, y positions of each grid tile
			std::pair<int, int> P;
			std::pair<int, int> A;
			std::pair<int, int> B;
			std::pair<int, int> C;

			// remove tiles from grid
			void clear();
			// add tiles to grid
			void build();

		public:
			Grid() = default;

			Grid(const Grid& other) = delete;
			Grid(Grid&& other) = delete;

			Grid& operator=(Grid&& other) = delete;
			Grid& operator=(const Grid& other) = delete;

			~Grid() = default;

			// display grid configuration
			void show();

			// return the positions of grid tiles
			std::pair<int, int> getP() const;
			std::pair<int, int> getA() const;
			std::pair<int, int> getB() const;
			std::pair<int, int> getC() const;

			// return the configuration of the grid
			std::array<std::array<char, grid_height>, grid_width> getConfiguration() const;
	};

	class StartGrid : public Grid
	{
		public:
			StartGrid();

			StartGrid(const Grid& other) = delete;
			Grid& operator=(const Grid& other) = delete;

			~StartGrid() = default;
	};

	class GoalGrid : public Grid
	{
		public:
			GoalGrid();

			GoalGrid(const Grid& other) = delete;
			Grid& operator=(const Grid& other) = delete;

			~GoalGrid() = default;
	};

	class StandardGrid : public Grid
	{
		public:
			StandardGrid() = delete;

			StandardGrid(const Grid& other);
			Grid& operator=(const Grid& other);
			
			~StandardGrid() = default;

			// compare the configuration of two grids
			bool isIdenticalTo(const Grid& other);

			// move the P tile within the grid
			void movePUp();
			void movePDown();
			void movePLeft();
			void movePRight();
	};
}

#endif
