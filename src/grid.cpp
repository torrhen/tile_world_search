#include "grid.hpp"

#include <iostream>

namespace TileSearch
{
	/* ========== Tile Class ========== */

	Tile::Tile(std::uint32_t x, std::uint32_t y, Letter ID)
		: position(std::make_pair(x, y)), ID(ID) 
	{}

	/* ========== End Tile Class ========== */

	/* ========== Grid Class ========== */

	Grid::Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C)
		: P(P), A(A), B(B), C(C), move_count(0)
	{
		build();
	}

	void Grid::build() noexcept
	{
		//temporarily remove all tiles from the grid
		configuration.fill({Letter::BLANK, Letter::BLANK, Letter::BLANK, Letter::BLANK});
		// y position of tiles indicate rows of the grid
		// x position of tiles indicate columns of the grid
		configuration[P.getY()][P.getX()] = P.ID;
		configuration[A.getY()][A.getX()] = A.ID;
		configuration[B.getY()][B.getX()] = B.ID;
		configuration[C.getY()][C.getX()] = C.ID;
	}

	void Grid::show() const noexcept
	{
		std::cout << "\n";
		std::cout << "\t" << move_count << "\n\n";
		// iterate over each row in reverse order so the grid is properly displayed within the console
		for (auto row = configuration.crbegin(); row != configuration.crend(); ++row)
		{
			std::cout << "\t| ";
			// iterate over each column of each row...
			for (auto col = row->cbegin(); col != row->cend(); ++col)
			{
				// print the character id located at the grid position
				std::cout << (char)*col << " | ";
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
		build();
	}

	void Grid::move_player(Direction value)
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

	// used to calculate the heuristic for tree nodes required by A* search
	std::uint32_t Grid::manhattan_distance_to(const Grid& Other) const
	{
		// calculate the horizontal distance between each tile in the current grid and the goal grid
		std::uint32_t x_distance = abs(P.getX() - Other.P.getX()) + abs(A.getX() - Other.A.getX()) 
							+ abs(B.getX() - Other.B.getX()) + abs(C.getX() - Other.C.getX());
		// calculate the vertical distance between each tile in the current grid and the goal grid
		std::uint32_t  y_distance = abs(P.getY() - Other.P.getY()) + abs(A.getY() - Other.A.getY()) 
							+ abs(B.getY() - Other.B.getY()) + abs(C.getY() - Other.C.getY());
		// return the combined manhattan distance of every tile
		return x_distance + y_distance;	
	}

	/* ========== End Grid Class ========== */

	bool operator==(const Grid& Left, const Grid& Right)
	{
		return (&Left == &Right) || (Left.get_configuration() == Right.get_configuration());
	}
}