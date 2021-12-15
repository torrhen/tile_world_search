#include "grid.hpp"

#include <iostream>
#include <cassert>

namespace tile_world_search
{
	/* ========== Tile Class ========== */

	Tile::Tile(std::uint32_t x, std::uint32_t y, Letter ID)
		: position(std::make_pair(x, y)), ID(ID) 
	{}

	/* ========== End Tile Class ========== */

	/* ========== Grid Class ========== */

	std::uint32_t Grid::width = 4;
	std::uint32_t Grid::height = 4;

	Grid::Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C)
		: P(P), A(A), B(B), C(C), move_count(0)
	{
		assert(("Grid must be square!", height == width));
		// build the intial grid
		for (std::size_t i = 0; i < height; ++i)
		{
			std::vector<Letter> row;
			for (std::size_t j = 0; j < width; ++j)
			{
				row.push_back(Letter::BLANK);
			}
			configuration.push_back(row);
		}

		place_tiles();
	}

	void Grid::place_tiles()
	{
		// temporarily remove all tiles from the grid
		for (auto row = configuration.begin(); row < configuration.end(); ++row)
		{
			std::fill(row->begin(), row->end(), Letter::BLANK);
		}
		// place tiles
		configuration[P.getY()][P.getX()] = P.ID;		// [column][row]
		configuration[A.getY()][A.getX()] = A.ID;
		configuration[B.getY()][B.getX()] = B.ID;
		configuration[C.getY()][C.getX()] = C.ID;
	}

	void Grid::show() const
	{
		std::cout << "\n";
		std::cout << "\t\tMove: " << move_count << "\n\n";
		// iterate over each row in reverse order so the grid is properly displayed within the console
		for (auto row = configuration.crbegin(); row != configuration.crend(); ++row)
		{
			std::cout << "\t\t";
			// iterate over each column of each row...
			for (auto col = row->cbegin(); col != row->cend(); ++col)
			{
				// print the character id located at the grid position
				std::cout << "[" << (char)*col << "]";
			}
			std::cout << "\n";
		}
		std::cout << "\n"; 
	}

	void Grid::move_player_by(std::int32_t x, std::int32_t y)
	{
		// swap player with any tile that exists in the new position
		if ((A.getX() == P.getX() + x) && (A.getY() == P.getY() + y))
		{
			(A.position).swap(P.position);
		}
		else if ((B.getX() == P.getX() + x) && (B.getY() == P.getY() + y))
		{
			(B.position).swap(P.position);
		}
		else if ((C.getX() == P.getX() + x) && (C.getY() == P.getY() + y))
		{
			(C.position).swap(P.position);
		}
		// otherwise move the player tile
		else
		{
			std::get<0>(P.position) += x;
			std::get<1>(P.position) += y;
		}
		move_count++;
		place_tiles();
	}

	void Grid::move_player(const Direction& value)
	{
		// check the player tile is not within the top row of the grid
		if (value == Direction::UP && P.getY() != height - 1)
		{
			// move the player upwards by 1 unit
			move_player_by(0,1);
		}
		// check the player tile is not within the bottom row of the grid
		else if (value == Direction::DOWN && P.getY() != 0)
		{
			// move the player down by 1 unit
			move_player_by(0,-1);
		}
		// check the player tile is not within the left column of the grid
		else if (value == Direction::LEFT && P.getX() != 0)
		{
			// move the player left by 1 unit
			move_player_by(-1,0);
		}
		// check the player tile is not within the right column of the grid
		else if (value == Direction::RIGHT && P.getX() != width - 1)
		{
			// move the player right by 1 unit
			move_player_by(1,0);
		}
	}

	/* ========== End Grid Class ========== */

	// (1) basic method to calculate the heuristic cost of nodes required by A* search
	std::uint32_t misplaced_tiles(const Grid& Left, const Grid& Right)
	{
		std::uint32_t total_tiles_misplaced = 0;
		// count how many of the tiles are different from their positions in the goal state
		if (!(Left.P.getX() == Right.P.getX() && Left.P.getY() == Right.P.getY()))
		{
			total_tiles_misplaced++;
		}
		if (!(Left.A.getX() == Right.A.getX() && Left.A.getY() == Right.A.getY()))
		{
			total_tiles_misplaced++;
		}
		if (!(Left.B.getX() == Right.B.getX() && Left.B.getY() == Right.B.getY()))
		{
			total_tiles_misplaced++;
		}
		if (!(Left.C.getX() == Right.C.getX() && Left.C.getY() == Right.C.getY()))
		{
			total_tiles_misplaced++;
		}
		return total_tiles_misplaced;
	}

	// (2) improved method to calculate the heuristic cost of nodes required by A* search
	std::uint32_t manhattan_distance(const Grid& Left, const Grid& Right)
	{
		// calculate the horizontal distance between each tile in the current grid and the goal grid
		std::uint32_t x_distance = abs(Left.P.getX() - Right.P.getX()) + abs(Left.A.getX() - Right.A.getX()) 
							+ abs(Left.B.getX() - Right.B.getX()) + abs(Left.C.getX() - Right.C.getX());
		// calculate the vertical distance between each tile in the current grid and the goal grid
		std::uint32_t  y_distance = abs(Left.P.getY() - Right.P.getY()) + abs(Left.A.getY() - Right.A.getY()) 
							+ abs(Left.B.getY() - Right.B.getY()) + abs(Left.C.getY() - Right.C.getY());
		// return the combined manhattan distance of every tile
		return x_distance + y_distance;	
	}

	bool operator==(const Grid& Left, const Grid& Right)
	{
		return (&Left == &Right) || (Left.get_configuration() == Right.get_configuration());
	}
}