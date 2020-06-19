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

			// grid constructor should only be accessed from derived classes
			Grid() = default;

			// grid copy/ move constructors should only be accessed from derived classes
			Grid(const Grid& other) = default;
			//Grid(Grid&& other) = delete;
			// grid copy/move assignment operators should only be accessed from derived classes
			Grid& operator=(const Grid& other) = default;
			//Grid& operator=(Grid&& other) = delete;

		public:
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

			// start grid should not copy/steal from another grid
			StartGrid(const Grid& other) = delete;
			StartGrid(Grid&& other) = delete;
			Grid& operator=(const Grid& other) = delete;
			Grid& operator=(Grid&& other) = delete;
	};

	class GoalGrid : public Grid
	{
		public:
			GoalGrid();

			// goal grid should not copy/steal from another grid
			GoalGrid(const Grid& other) = delete;
			GoalGrid(Grid&& other) = delete;
			Grid& operator=(const Grid& other) = delete;
			Grid& operator=(Grid&& other) = delete;
	};

	class StandardGrid : public Grid
	{
		public:
			// standard grid should only copy/steal from another grid
			StandardGrid() = delete;

			StandardGrid(const Grid& other);
			// StandardGrid(Grid&& other) = delete;
			Grid& operator=(const Grid& other);
			// Grid& operator=(Grid&& other) = delete;

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
