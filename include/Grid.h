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
			static constexpr std::size_t width = 4;
			static constexpr std::size_t height = 4;

			std::array<std::array<char, height>, width> configuration;

			// store x, y positions of each grid tile
			std::pair<int, int> P;
			std::pair<int, int> A;
			std::pair<int, int> B;
			std::pair<int, int> C;

			// remove tiles from grid
			void clear();
			// add tiles to grid
			void build();

			// Grid class should not be initialised directly
			Grid(std::pair<int, int> P, std::pair<int, int> A, std::pair<int, int> B, std::pair<int, int> C);

		public:
			// display grid configuration
			void show();

			// return the positions of grid tiles
			std::pair<int, int> getP() const;
			std::pair<int, int> getA() const;
			std::pair<int, int> getB() const;
			std::pair<int, int> getC() const;

			// return the configuration of the grid
			std::array<std::array<char, height>, width> getConfiguration() const;
	};

	class StartGrid : public Grid
	{
		public:
			StartGrid(std::pair<int, int> P, std::pair<int, int> A, std::pair<int, int> B, std::pair<int, int> C);

			// start grid should not copy/steal from another grid
			StartGrid(const StartGrid& other) = delete;
			StartGrid(StartGrid&& other) = delete;

			StartGrid& operator=(const StartGrid& other) = delete;
			StartGrid& operator=(StartGrid&& other) = delete;
	};

	class GoalGrid : public Grid
	{
		public:
			GoalGrid(std::pair<int, int> P, std::pair<int, int> A, std::pair<int, int> B, std::pair<int, int> C);

			// goal grid should not copy/steal from another grid
			GoalGrid(const GoalGrid& other) = delete;
			GoalGrid(GoalGrid&& other) = delete;

			GoalGrid& operator=(const GoalGrid& other) = delete;
			GoalGrid& operator=(GoalGrid&& other) = delete;
	};

	class StandardGrid : public Grid
	{
		public:
			// standard grid should only be created using another grid
			StandardGrid(const StartGrid& other);

			// two grids are identical if they have the exact same configuration
			bool operator==(const Grid& other);

			// move the P tile within the grid
			void movePUp();
			void movePDown();
			void movePLeft();
			void movePRight();
	};
}

#endif
