#include "../include/Grid.h"

#include <iostream>

namespace TileSearch
{
	/* ========== Tile Class ========== */

	Tile::Tile(uint x, uint y, char id)
		: position(std::make_pair(x, y)), id(id) 
	{}

	/* ========== Grid Class ========== */

	Grid::Grid(const Tile& P, const Tile& A, const Tile& B, const Tile& C)
		: P(P), A(A), B(B), C(C), move_count(0)
	{
		build();
	}

	// temporarily remove all tiles from the grid
	void Grid::clear() noexcept
	{
		// iterate over each row of the grid...
		for (std::array<std::array<char, height>, width>::iterator row = configuration.begin(); 
					row != configuration.end(); ++row)
		{
			// iterate over each column of each row...
			for (std::array<char, width>::iterator col = row->begin(); col != row->end(); ++col)
			{
				// mark the grid position as blank
				*col = '-';
			}
		}
	}

	// place the P, A, B and C tiles
	void Grid::build() noexcept
	{
		clear();
		// y position as first index, x position as second index so that the configuration is properly displayed to the console
		configuration[P.getY()][P.getX()] = P.id;
		configuration[A.getY()][A.getX()] = A.id;
		configuration[B.getY()][B.getX()] = B.id;
		configuration[C.getY()][C.getX()] = C.id;
	}

	void Grid::show() const noexcept
	{
		std::cout << "\n";
		std::cout << "\t" << move_count << "\n\n";

		// iterate over each row in reverse order so the grid is properly displayed within the console
		for (std::array<std::array<char, height>, width>::const_reverse_iterator row = configuration.crbegin(); row != configuration.crend(); ++row)
		{
			std::cout << "\t| ";
			// iterate over each column of each row...
			for (std::array<char, width>::const_iterator col = row->cbegin(); col != row->cend(); ++col)
			{
				// print the contents of the grid position
				std::cout << *col << " | ";
			}
			std::cout << "\n";
		}
		std::cout << "\n"; 
		//std::cout << "                =========================\n";
	}

	void Grid::move_P_up() noexcept
	{
		// check P can move upwards
		if (P.getY() != height - 1)
		{
			// swap P with any tile in the new position
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
			// otherwise move P upwards
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
		// check P can move downwards
		if (P.getY() != 0)
		{
			// swap P with any tile in the new position
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
			// otherwise move P downwards
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
		// check P can move right
		if (P.getX() != width - 1)
		{
			// swap P with any tile in the new position
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
			// otherwise move P right
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
		// if P can move left...
		if (P.getX() != 0)
		{
			// swap P with any tile in the new position
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
			// otherwise move P left
			else
			{
				std::get<0>(P.position)--;
			}
			move_count++;
			build();
		}
	}

	// compare the configuration of two grids
	bool operator==(const Grid& Left, const Grid& Right)
	{
		return (&Left == &Right) || (Left.get_configuration() == Right.get_configuration());
	}
}