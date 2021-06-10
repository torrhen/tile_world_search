#ifndef GRID_H
#define GRID_H

#include <array>
#include <utility>
#include <cstdint>

namespace TileSearch
{
	enum class Letter : char
	{
		P = 'P', A = 'A', B = 'B', C = 'C', BLANK = '-'
	};

	enum class Direction : std::uint32_t
	{
		UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4
	};

	class Tile 
	{
		// allows the modification of each tile position by the grid class during movements of the P tile
		friend class Grid;
	private:
		// store the position and id of each grid tile
		std::pair<std::uint32_t, std::uint32_t> position;
		Letter ID;
		// get methods are used for easier understanding
		std::uint32_t getX() const { return std::get<0>(position); }
		std::uint32_t getY() const { return std::get<1>(position); }

	public:
		Tile(std::uint32_t x, std::uint32_t y, Letter ID);
	};

	class Grid
	{
	private:
		static constexpr std::uint32_t width = 4;
		static constexpr std::uint32_t height = 4;
		// store the locations of each tile in a 2D array
		std::array<std::array<Letter, height>, width> configuration;
		Tile P, A, B, C;
		// count the current total number of moves made by the P tile
		std::uint32_t move_count;
		// place the tiles in their grid positions
		void build() noexcept;
		// move the player tile
		void move_player_by(std::int32_t x, std::int32_t y);

	public:
		Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C);
		// display the current configuration of the grid to the console
		void show() const noexcept;
		void move_player(Direction value);
		// calculate the total manhattan distance between every tile in the current configuration compared to the goal configuration
		std::uint32_t manhattan_distance_to(const Grid& Other) const;
		auto& get_configuration() const { return configuration; }
	};
	// check if two grids have identical configurations
	bool operator==(const Grid& Left, const Grid& Right);
}

#endif
