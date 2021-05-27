#include "../include/Grid.h"

#include <iostream>

namespace TileSearch
{
	/* ========== Tile Class ========== */

	Tile::Tile(uint x, uint y, Letter ID)
		: position(std::make_pair(x, y)), ID(ID) 
	{}

	/* ========== End Tile Class ========== */

	/* ========== Grid Class ========== */

	Grid::Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C)
		: P(P), A(A), B(B), C(C), move_count(0)
	{
		build();
	}

	void Grid::clear() noexcept
	{
		// iterate over each row of the grid...
		for (auto row = configuration.begin(); row != configuration.end(); ++row)
		{
			// iterate over each column of each row...
			for (auto col = row->begin(); col != row->end(); ++col)
			{
				// mark the grid position as blank
				*col = Letter::BLANK;
			}
		}
	}

	// build() throws no exception provided that the starting position of every tile lies within the grid
	// this will be guaranteed by the final program, but should be highlighted
	void Grid::build() noexcept
	{
		clear();
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

	void Grid::move_P_up() noexcept
	{
		// check the P tile is not within the top row of the grid
		if (P.getY() != height - 1)
		{
			// swap P with any tile that exists in the new position
			if ((A.getY() == P.getY() + 1) && (A.getX() == P.getX()))
			{
				(A.position).swap(P.position);
			}
			else if ((B.getY() == P.getY() + 1) && (B.getX() == P.getX()))
			{
				(B.position).swap(P.position);
			}
			else if ((C.getY() == P.getY() + 1) && (C.getX() == P.getX()))
			{
				(C.position).swap(P.position);
			}
			// otherwise move the P tile up
			else
			{
				std::get<1>(P.position)++;
			}
			move_count++;
			build();
		}
	}

	void Grid::move_P_down() noexcept
	{
		// check the P tile is not within the bottom row of the grid
		if (P.getY() != 0)
		{
			// swap P with any tile that exists in the new position
			if ((A.getY() == P.getY() - 1) && (A.getX() == P.getX()))
			{
				(A.position).swap(P.position);
			}
			else if ((B.getY() == P.getY() - 1) && (B.getX() == P.getX()))
			{
				(B.position).swap(P.position);
			}
			else if ((C.getY() == P.getY() - 1) && (C.getX() == P.getX()))
			{
				(C.position).swap(P.position);
			}
			// otherwise move the P tile down
			else
			{
				std::get<1>(P.position)--;
			}
			move_count++;
			build();
		}
	}

	void Grid::move_P_right() noexcept
	{
		// check the P tile is not within the last column of the grid
		if (P.getX() != width - 1)
		{
			// swap P with any tile that exists in the new position
			if ((A.getX() == P.getX() + 1) && (A.getY() == P.getY()))
			{	
				(A.position).swap(P.position);
			}
			else if ((B.getX() == P.getX() + 1) && (B.getY() == P.getY()))
			{
				(B.position).swap(P.position);
			}
			else if ((C.getX() == P.getX() + 1) && (C.getY() == P.getY()))
			{
				(C.position).swap(P.position);
			}
			// otherwise move the P tile right
			else
			{
				std::get<0>(P.position)++;
			}
			move_count++;
			build();
		}
	}

	void Grid::move_P_left() noexcept
	{
		// check the P tile is not within the first column of the grid
		if (P.getX() != 0)
		{
			// swap P with any tile that exists in the new position
			if ((A.getX() == P.getX() - 1) && (A.getY() == P.getY()))
			{
				(A.position).swap(P.position);
			}
			else if ((B.getX() == P.getX() - 1) && (B.getY() == P.getY()))
			{
				(B.position).swap(P.position);
			}
			else if ((C.getX() == P.getX() - 1) && (C.getY() == P.getY()))
			{
				(C.position).swap(P.position);
			}
			// otherwise move the P tile left
			else
			{
				std::get<0>(P.position)--;
			}
			move_count++;
			build();
		}
	}

	// used to calculate the heuristic for tree nodes required by A* search
	uint Grid::manhattan_distance_to(const Grid& Other) const
	{
		// calculate the horizontal distance between each tile in the current grid and the goal grid
		uint x_distance = abs(P.getX() - Other.P.getX()) + abs(A.getX() - Other.A.getX()) 
							+ abs(B.getX() - Other.B.getX()) + abs(C.getX() - Other.C.getX());
		// calculate the vertical distance between each tile in the current grid and the goal grid
		uint y_distance = abs(P.getY() - Other.P.getY()) + abs(A.getY() - Other.A.getY()) 
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