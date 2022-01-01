#ifndef GRID_H
#define GRID_H

#include <vector>
#include <utility>
#include <cstdint>

namespace tile_world_search
{
	enum class Letter : char 
	{
		P = 'P', A = 'A', B = 'B', C = 'C', BLANK = ' '
	};

	class Tile 
	{
	// grid class should modify the x, y position of a tile during movement
	friend class Grid;
	public:
		Tile(std::uint32_t x, std::uint32_t y, Letter ID);
		std::uint32_t getX() const { return std::get<0>(position); }
		std::uint32_t getY() const { return std::get<1>(position); }
	private:
		std::pair<std::uint32_t, std::uint32_t> position;
		Letter ID;
	};

	enum class Direction : std::uint32_t
	{
		UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4
	};

	class Grid
	{
	// heuristic functions
	friend std::uint32_t manhattan_distance(const Grid& Left, const Grid& Right);
	friend std::uint32_t misplaced_tiles(const Grid& Left, const Grid& Right);
	public:
		Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C);
		// display the current configuration of the grid to the console
		void show() const;
		void move_player(const Direction& value);
		auto& get_configuration() const { return configuration; }
	private:
		static std::uint32_t width;
		static std::uint32_t height;
		// stores the id of each tile
		std::vector<std::vector<Letter>> configuration;
		Tile P, A, B, C;
		// stores the current total number of moves made by the player tile
		std::uint32_t move_count;
		// place the tiles in their grid positions
		void place_tiles();
		// move the player tile by x and y
		void move_player_by(std::int32_t x, std::int32_t y);
	};

	// calculate the number of misplaced tiles between the goal grid
	std::uint32_t misplaced_tiles(const Grid& Left, const Grid& Right);
	// calculate the total manhattan distance of tiles between the goal grid (admissable)
	std::uint32_t manhattan_distance(const Grid& Left, const Grid& Right);
	// check if two grids have identical configurations
	bool operator==(const Grid& Left, const Grid& Right);
}

#endif
