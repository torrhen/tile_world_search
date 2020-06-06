#include "../lib/Grid.h"

#include <iostream>
#include <array>

namespace TileSearch
{
	// constructor
	Grid::Grid()
		: P{3, 0, 'P'}, A{2, 0, 'A'}, B{1, 0, 'B'}, C{0, 0, 'C'}
	{
		placeTiles();
	}

	// copy constructor
	Grid::Grid(const Grid& Other)
	{
		this->P = {Other.P.x, Other.P.y, Other.P.id};
		this->A = {Other.A.x, Other.A.y, Other.A.id};
		this->B = {Other.B.x, Other.B.y, Other.B.id};
		this->C = {Other.C.x, Other.C.y, Other.C.id};
		placeTiles();
	}

	// copy assignment operator 
	Grid& Grid::operator=(const Grid& Other)
	{
		this->P = {Other.P.x, Other.P.y, Other.P.id};
		this->A = {Other.A.x, Other.A.y, Other.A.id};
		this->B = {Other.B.x, Other.B.y, Other.B.id};
		this->C = {Other.C.x, Other.C.y, Other.C.id};
		placeTiles();	

		return *this;
	}

	// move constructor
	Grid::Grid(Grid&& Other)
	{
		this->P = {Other.P.x, Other.P.y, Other.P.id};
		this->A = {Other.A.x, Other.A.y, Other.A.id};
		this->B = {Other.B.x, Other.B.y, Other.B.id};
		this->C = {Other.C.x, Other.C.y, Other.C.id};
		placeTiles();

		Other.clearTiles();
		Other.isEmpty = true;
	}

	// move assignment operator
	Grid& Grid::operator=(Grid&& Other)
	{
		this->P = {Other.P.x, Other.P.y, Other.P.id};
		this->A = {Other.A.x, Other.A.y, Other.A.id};
		this->B = {Other.B.x, Other.B.y, Other.B.id};
		this->C = {Other.C.x, Other.C.y, Other.C.id};
		placeTiles();

		Other.clearTiles();
		Other.isEmpty = true;

		return *this;
	}

	// destructor
	Grid::~Grid()
	{

	}

	// temporarily remove board tiles
	void Grid::clearTiles()
	{
		configuration = 
		{{
			{'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X'}
		}};
	}

	// place the P, A, B and C tiles in their positions
	void Grid::placeTiles()
	{
		clearTiles();
		configuration[P.x][P.y] = P.id;
		configuration[A.x][A.y] = A.id;
		configuration[B.x][B.y] = B.id;
		configuration[C.x][C.y] = C.id;
	}

	// move P tile 

	void Grid::movePUp()
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
			placeTiles();
		}
		// otherwise do nothing
	}

	void Grid::movePDown()
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
			placeTiles();
		}
		// otherwise do nothing
	}

	void Grid::movePRight()
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
			placeTiles();
		}
		// otherwise do nothing
	}

	void Grid::movePLeft()
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
			placeTiles();
		}
		// otherwise do nothing
	}

	// display board configuration
	void Grid::show()
	{
		if (!isEmpty)
		{
			std::cout << "\n";
			for (int i = height - 1; i >= 0; --i)
			{
				std::cout << "| ";
				for (int j = 0; j < width; ++j)
				{
					std::cout << configuration[j][i] << " | ";
				}
				std::cout << "\n";
			}
		}
	}
}