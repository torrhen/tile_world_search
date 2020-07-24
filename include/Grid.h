#ifndef GRID_H
#define GRID_H

#include <array>
#include <utility>

namespace TileSearch
{
	// store position and id of each grid tile
	class Tile 
	{
		friend class Grid;

	private:
		std::pair<unsigned int, unsigned int> position;
		char id;

		unsigned int getX() const { return std::get<0>(position); }
		unsigned int getY() const { return std::get<1>(position); }

	public:
		Tile(unsigned int x, unsigned int y, char id);
	};

	// store and manage the locations of each tile
	class Grid
	{
	private:
		// set dimensions of grid
		static constexpr unsigned int width = 4;
		static constexpr unsigned int height = 4;
		// store tile locations
		std::array<std::array<char, height>, width> configuration;

		Tile P, A, B, C;

		// remove tiles from grid
		void clear() noexcept;
		// place tiles within grid
		void build() noexcept;

	public:
		Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C);

		// display the configuration to the console
		void show() const noexcept;
		// move P tile
		void movePUp() noexcept;
		void movePDown() noexcept;
		void movePLeft() noexcept;
		void movePRight() noexcept;

		// return the configuration of the grid
		const std::array<std::array<char, height>, width>& getConfiguration() const { return configuration; }
	};

	// check if two grids have identical configurations
	bool operator==(const Grid& lhs, const Grid& rhs);
}

#endif
