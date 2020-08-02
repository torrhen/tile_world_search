#ifndef GRID_H
#define GRID_H

#include <array>
#include <utility>

namespace TileSearch
{
	typedef unsigned int uint;

	class Tile 
	{
		// allows the modification of each tile position by the grid class during movements of the P tile
		friend class Grid;
	private:
		// store the position and id of each grid tile
		std::pair<uint, uint> position;
		char id;
		// get methods are used for easier understanding
		uint getX() const { return std::get<0>(position); }
		uint getY() const { return std::get<1>(position); }

	public:
		Tile(uint x, uint y, char id);
	};

	class Grid
	{
	private:
		static constexpr uint width = 4;
		static constexpr uint height = 4;
		// store the locations of each tile in a 2d array
		std::array<std::array<char, height>, width> configuration;
		Tile P, A, B, C;
		// count the current total number of moves made by the P tile
		uint move_count;
		// temporarily remove grid tiles from the configuration while their positions are updated
		void clear() noexcept;
		// place the tiles in their new grid positions
		void build() noexcept;

	public:
		Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C);
		// display the current configuration of the grid to the console
		void show() const noexcept;
		void move_P_up() noexcept;
		void move_P_down() noexcept;
		void move_P_left() noexcept;
		void move_P_right() noexcept;
		// calculate the total manhattan distance between every tile in the current configuration compared to the goal configuration
		uint manhattan_distance_to(const Grid& Other) const;
		const std::array<std::array<char, height>, width>& get_configuration() const { return configuration; }
	};
	// check if two grids have identical configurations
	bool operator==(const Grid& Left, const Grid& Right);
}

#endif
