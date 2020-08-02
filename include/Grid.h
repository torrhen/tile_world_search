#ifndef GRID_H
#define GRID_H

#include <array>
#include <utility>

namespace TileSearch
{
	typedef unsigned int uint;

	// store position and id of each grid tile
	class Tile 
	{
		friend class Grid;

	private:
		std::pair<uint, uint> position;
		char id;

		uint getX() const { return std::get<0>(position); }
		uint getY() const { return std::get<1>(position); }

	public:
		Tile(uint x, uint y, char id);
	};

	// store and manage the locations of each tile
	class Grid
	{

	private:
		// set dimensions of grid
		static constexpr uint width = 4;
		static constexpr uint height = 4;
		// store tile locations
		std::array<std::array<char, height>, width> configuration;

		Tile P, A, B, C;
		uint move_count;

		// remove tiles from grid
		void clear() noexcept;
		// place tiles within grid
		void build() noexcept;

	public:
		Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C);

		// display the configuration to the console
		void show() const noexcept;
		// move P tile
		void move_P_up() noexcept;
		void move_P_down() noexcept;
		void move_P_left() noexcept;
		void move_P_right() noexcept;

		uint manhattan_distance_to(const Grid& Other) const;

		// return the configuration of the grid
		const std::array<std::array<char, height>, width>& get_configuration() const { return configuration; }

	};

	// check if two grids have identical configurations
	bool operator==(const Grid& Left, const Grid& Right);
}

#endif
