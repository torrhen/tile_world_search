#include "../include/Grid.h"

#include <iostream>
#include <array>
#include <exception>
#include <iterator>

namespace TileSearch
{
	Grid::Grid()
		: P{3, 0, 'P'}, A{0, 0, 'A'}, B{1, 0, 'B'}, C{2, 0, 'C'}
	{
		build();
	}

	Grid::Grid(const Grid& other)
	{
		this->P = {other.P.x, other.P.y, other.P.id};
		this->A = {other.A.x, other.A.y, other.A.id};
		this->B = {other.B.x, other.B.y, other.B.id};
		this->C = {other.C.x, other.C.y, other.C.id};
		build();
	}

	Grid& Grid::operator=(const Grid& other)
	{
		// self assignment check
		if (&other != this)
		{
			this->P = {other.P.x, other.P.y, other.P.id};
			this->A = {other.A.x, other.A.y, other.A.id};
			this->B = {other.B.x, other.B.y, other.B.id};
			this->C = {other.C.x, other.C.y, other.C.id};
			build();

		}
		return *this;
	}

	Grid::Grid(Grid&& other)
	{
		this->P = {other.P.x, other.P.y, other.P.id};
		this->A = {other.A.x, other.A.y, other.A.id};
		this->B = {other.B.x, other.B.y, other.B.id};
		this->C = {other.C.x, other.C.y, other.C.id};
		build();

		other.clear();
		other.isEmpty = true;
	}

	Grid& Grid::operator=(Grid&& other)
	{
		// self assignment check
		if (&other != this)
		{
			this->P = {other.P.x, other.P.y, other.P.id};
			this->A = {other.A.x, other.A.y, other.A.id};
			this->B = {other.B.x, other.B.y, other.B.id};
			this->C = {other.C.x, other.C.y, other.C.id};
			build();

			other.clear();
			other.isEmpty = true;
		}
		return *this;
	}

	Grid::~Grid()
	{

	}

	// temporarily remove grid tiles
	void Grid::clear()
	{
		for (std::array<std::array<char, height>, width>::iterator row = configuration.begin(); 
					row != configuration.end(); ++row)
		{
			for (std::array<char, width>::iterator col = row->begin(); col != row->end(); ++col)
			{
				*col = '-';
			}
		}
	}

	// place the P, A, B and C tiles in their positions
	void Grid::build()
	{
		clear();
		try
		{
			configuration.at(P.y).at(P.x) = P.id;
			configuration.at(A.y).at(A.x) = A.id;
			configuration.at(B.y).at(B.x) = B.id;
			configuration.at(C.y).at(C.x) = C.id;
		}
		catch (std::out_of_range)
		{
			std::cout << "Could not build grid." << std::endl;
		}

	}

	// move the P tile up, down, right and left
	void Grid::movePUp() noexcept
	{
		// if P can move upwards...
		if (P.y != height - 1)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if (A.y == P.y + 1 and A.x == P.x)
			{
				A.y = P.y;
			}
			else if (B.y == P.y + 1 and B.x == P.x)
			{
				B.y = P.y;
			}
			else if (C.y == P.y + 1 and C.x == P.x)
			{
				C.y = P.y;
			}
			// move P up
			P.y += 1;
			build();
		}
		// otherwise do nothing
	}

	void Grid::movePDown() noexcept
	{
		// if P can move downwards...
		if (P.y != 0)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if (A.y == P.y - 1 and A.x == P.x)
			{
				A.y = P.y;
			}
			else if (B.y == P.y - 1 and B.x == P.x)
			{
				B.y = P.y;
			}
			else if (C.y == P.y - 1 and C.x == P.x)
			{
				C.y = P.y;
			}
			// move P down
			P.y -= 1;
			build();
		}
		// otherwise do nothing
	}

	void Grid::movePRight() noexcept
	{
		// if P can move right...
		if (P.x != width - 1)
		{
			if (A.x == P.x + 1 and A.y == P.y)
			{	
				A.x = P.x;
			}
			else if (B.x == P.x + 1 and B.y == P.y)
			{
				B.x = P.x;
			}
			else if (C.x == P.x + 1 and C.y == P.y)
			{
				C.x = P.x;
			}
			// move P right
			P.x += 1;
			build();
		}
		// otherwise do nothing
	}

	void Grid::movePLeft() noexcept
	{
		// if P can move left...
		if (P.x != 0)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if (A.x == P.x - 1 and A.y == P.y)
			{
				A.x = P.x;
			}
			else if (B.x == P.x - 1 and B.y == P.y)
			{
				B.x = P.x;
			}
			else if (C.x == P.x - 1 and C.y == P.y)
			{
				C.x = P.x;
			}
			// move P left
			P.x -= 1;
			build();
		}
		// otherwise do nothing
	}

	// compare configuration between grids
	bool Grid::isIdenticalTo(const Grid& other)
	{
		if (this->configuration == other.configuration)
		{
			return true;
		}
		return false;
	}

	bool Grid::isGoal()
	{
		if ((P.x == P_goal.x && P.y == P_goal.y) && (A.x == A_goal.x && A.y == A_goal.y) &&
				(B.x == B_goal.x && B.y == B_goal.y) && (C.x == C_goal.x && C.y == C_goal.y))
		{
			return true;
		}
		return false;
	}


	// display grid configuration
	void Grid::show()
	{
		if (!isEmpty)
		{
			std::cout << "\n";
			for (std::array<std::array<char, height>, width>::reverse_iterator row = configuration.rbegin(); 
					row != configuration.rend(); ++row)
			{
				std::cout << "| ";
				for (std::array<char, width>::iterator col = row->begin(); col != row->end(); ++col)
				{
					std::cout << *col << " | ";
				}
				std::cout << "\n";
			}
		}
	}
}