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

			bool isEmpty = false;

		public:
			Grid() = default;
			Grid(const Grid& other) = delete;
			Grid& operator=(const Grid& other) = delete;
			Grid(Grid&& other) = delete;
			Grid& operator=(Grid&& other) = delete;
			~Grid() = default;

			void clear();
			void build();
			void show();

			std::pair<int, int> getP() const;
			std::pair<int, int> getA() const;
			std::pair<int, int> getB() const;
			std::pair<int, int> getC() const;
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

			// bool isIdenticalTo(const Grid& other);

			// move the P tile
			void movePUp();
			void movePDown();
			void movePLeft();
			void movePRight();
	};
}

#endif
