#include "../include/Grid.h"

#include <iostream>
#include <array>
#include <exception>
#include <iterator>

namespace TileSearch
{
	/* ========== Grid Class ========== */

	Grid::Grid(std::pair<int, int> P, std::pair<int, int> A, std::pair<int, int> B, std::pair<int, int> C)
		: P(P), A(A), B(B), C(C)
	{
		// build the grid
		build();
	}

	// temporarily remove all tiles from the grid
	void Grid::clear()
	{
		// iterate over each row of the grid...
		for (std::array<std::array<char, height>, width>::iterator row = configuration.begin(); 
					row != configuration.end(); ++row)
		{
			// iterate over each column of each row...
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
			// y position placed in first index, x position placed in second index
			// this is done so that the configuration of the grid is properly displayed to the console
			configuration.at(std::get<1>(P)).at(std::get<0>(P)) = 'P';
			configuration.at(std::get<1>(A)).at(std::get<0>(A)) = 'A';
			configuration.at(std::get<1>(B)).at(std::get<0>(B)) = 'B';
			configuration.at(std::get<1>(C)).at(std::get<0>(C)) = 'C';
		}
		catch (std::out_of_range)
		{
			std::cout << "Could not build grid." << std::endl;
		}
	}

	// display grid configuration
	void Grid::show()
	{
		std::cout << "\n";
		// iterate over each row (in reverse order)...
		// reversing the order allows the grid to be properly displayed within the console
		for (std::array<std::array<char, height>, width>::reverse_iterator row = configuration.rbegin(); row != configuration.rend(); ++row)
		{
			std::cout << "                    | ";
			// iterate over each column of each row...
			for (std::array<char, width>::iterator col = row->begin(); col != row->end(); ++col)
			{
				std::cout << *col << " | ";
			}
			std::cout << "\n";
		}
		std::cout << "\n"; 
		std::cout << "                =========================" << std::endl;
	}

	// return the position of tiles P, A, B and C
	std::pair<int, int> Grid::getP() const
	{
		return P;
	}

	std::pair<int, int> Grid::getA() const
	{
		return A;
	}

	std::pair<int, int> Grid::getB() const
	{
		return B;
	}

	std::pair<int, int> Grid::getC() const
	{
		return C;
	}

	// return the configuration of the grid
	std::array<std::array<char, Grid::height>, Grid::width> Grid::getConfiguration() const
	{
		return configuration;
	}

	/* ========== Start Grid Class ========== */

	StartGrid::StartGrid(std::pair<int, int> P, std::pair<int, int> A, std::pair<int, int> B, std::pair<int, int> C)
		: Grid(P, A, B, C)
	{

	}

	/* ========== Goal Grid Class ========== */

	GoalGrid::GoalGrid(std::pair<int, int> P, std::pair<int, int> A, std::pair<int, int> B, std::pair<int, int> C)
		: Grid(P, A, B, C)
	{

	}

	/* ========== Standard Grid Class ========== */

	StandardGrid::StandardGrid(const Grid& other)
		: Grid(other.getP(), other.getA(), other.getB(), other.getC())
	{

	}

	Grid& StandardGrid::operator=(const Grid& other)
	{
		// copy the positions of each tile
		P = other.getP();
		A = other.getA();
		B = other.getB();
		C = other.getC();
		// build the grid	
		build();
		return *this;
	}

	// move the P tile up, down, right and left
	void StandardGrid::movePUp()
	{
		// if P can move upwards...
		if (std::get<1>(P) != height - 1)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if ((std::get<1>(A) == std::get<1>(P) + 1) and (std::get<0>(A) == std::get<0>(P)))
			{
				A.swap(P);
			}
			else if ((std::get<1>(B) == std::get<1>(P) + 1) and (std::get<0>(B) == std::get<0>(P)))
			{
				B.swap(P);
			}
			else if ((std::get<1>(C) == std::get<1>(P) + 1) and (std::get<0>(C) == std::get<0>(P)))
			{
				C.swap(P);
			}
			// rebuild grid
			build();
		}
		// otherwise do nothing
	}

	void StandardGrid::movePDown()
	{
		// if P can move downwards...
		if (std::get<1>(P) != 0)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if ((std::get<1>(A) == std::get<1>(P) - 1) and (std::get<0>(A) == std::get<0>(P)))
			{
				A.swap(P);
			}
			else if ((std::get<1>(B) == std::get<1>(P) - 1) and (std::get<0>(B) == std::get<0>(P)))
			{
				B.swap(P);
			}
			else if ((std::get<1>(C) == std::get<1>(P) - 1) and (std::get<0>(C) == std::get<0>(P)))
			{
				C.swap(P);
			}
			// rebuild grid
			build();
		}
		// otherwise do nothing
	}

	void StandardGrid::movePRight()
	{
		// if P can move right...
		if (std::get<0>(P) != width - 1)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if ((std::get<0>(A) == std::get<0>(P) + 1) and (std::get<1>(A) == std::get<1>(P)))
			{	
				A.swap(P);
			}
			else if ((std::get<0>(B) == std::get<0>(P) + 1) and (std::get<1>(B) == std::get<1>(P)))
			{
				B.swap(P);
			}
			else if ((std::get<0>(C) == std::get<0>(P) + 1) and (std::get<1>(C) == std::get<1>(P)))
			{
				C.swap(P);
			}
			// rebuild grid
			build();
		}
		// otherwise do nothing
	}

	void StandardGrid::movePLeft()
	{
		// if P can move left...
		if (std::get<0>(P) != 0)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if ((std::get<0>(A) == std::get<0>(P) - 1) and (std::get<1>(A) == std::get<1>(P)))
			{
				A.swap(P);
			}
			else if ((std::get<0>(B) == std::get<0>(P) - 1) and (std::get<1>(B) == std::get<1>(P)))
			{
				B.swap(P);
			}
			else if ((std::get<0>(C) == std::get<0>(P) - 1) and (std::get<1>(C) == std::get<1>(P)))
			{
				C.swap(P);
			}
			// rebuild grid
			build();
		}
		// otherwise do nothing
	}

	// compare the configuration of two grids
	bool StandardGrid::operator==(const Grid& other)
	{
		if ((&other == this) or (configuration == other.getConfiguration()))
		{
			return true;
		}
		return false;
	}
}