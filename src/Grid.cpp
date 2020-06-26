#include "../include/Grid.h"

#include <iostream>
#include <array>
#include <exception>
#include <iterator>

namespace TileSearch
{
	/* ========== Grid Class ========== */

	Grid::Grid(tile P, tile A, tile B, tile C)
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
			configuration.at(getYPosition(P)).at(getXPosition(P)) = 'P';
			configuration.at(getYPosition(A)).at(getXPosition(A)) = 'A';
			configuration.at(getYPosition(B)).at(getXPosition(B)) = 'B';
			configuration.at(getYPosition(C)).at(getXPosition(C)) = 'C';
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

	// move the P tile up, down, right and left
	void Grid::movePUp()
	{
		// if P can move upwards...
		if (getYPosition(P) != height - 1)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if ((getYPosition(A) == getYPosition(P) + 1) and (getXPosition(A) == getXPosition(P)))
			{
				A.swap(P);
			}
			else if ((getYPosition(B) == getYPosition(P) + 1) and (getXPosition(B) == getXPosition(P)))
			{
				B.swap(P);
			}
			else if ((getYPosition(C) == getYPosition(P) + 1) and (getXPosition(C) == getXPosition(P)))
			{
				C.swap(P);
			}
			else
			{
				// move P upwards
				std::get<1>(P) += 1;
			}
			// rebuild grid
			build();
		}
		// otherwise do nothing
	}

	void Grid::movePDown()
	{
		// if P can move downwards...
		if (getYPosition(P) != 0)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if ((getYPosition(A) == getYPosition(P) - 1) and (getXPosition(A) == getXPosition(P)))
			{
				A.swap(P);
			}
			else if ((getYPosition(B) == getYPosition(P) - 1) and (getXPosition(B) == getXPosition(P)))
			{
				B.swap(P);
			}
			else if ((getYPosition(C) == getYPosition(P) - 1) and (getXPosition(C) == getXPosition(P)))
			{
				C.swap(P);
			}
			else
			{
				// move P downwards
				std::get<1>(P) -= 1;
			}
			// rebuild grid
			build();
		}
		// otherwise do nothing
	}

	void Grid::movePRight()
	{
		// if P can move right...
		if (getXPosition(P) != width - 1)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if ((getXPosition(A) == getXPosition(P) + 1) and (getYPosition(A) == getYPosition(P)))
			{	
				A.swap(P);
			}
			else if ((getXPosition(B) == getXPosition(P) + 1) and (getYPosition(B) == getYPosition(P)))
			{
				B.swap(P);
			}
			else if ((getXPosition(C) == getXPosition(P) + 1) and (getYPosition(C) == getYPosition(P)))
			{
				C.swap(P);
			}
			else
			{
				// move P right
				std::get<0>(P) += 1;
			}
			// rebuild grid
			build();
		}
		// otherwise do nothing
	}

	void Grid::movePLeft()
	{
		// if P can move left...
		if (getXPosition(P) != 0)
		{
			// if the new position of P is taken...
			// swap the tile in the new position with P
			if ((getXPosition(A) == getXPosition(P) - 1) and (getYPosition(A) == getYPosition(P)))
			{
				A.swap(P);
			}
			else if ((getXPosition(B) == getXPosition(P) - 1) and (getYPosition(B) == getYPosition(P)))
			{
				B.swap(P);
			}
			else if ((getXPosition(C) == getXPosition(P) - 1) and (getYPosition(C) == getYPosition(P)))
			{
				C.swap(P);
			}
			else
			{
				// move P left
				std::get<0>(P) -= 1;
			}
			// rebuild grid
			build();
		}
		// otherwise do nothing
	}

	// compare the configuration of two grids
	bool operator==(const Grid &first, const Grid &second)
	{
		if ((&first == &second) or (first.getConfiguration() == second.getConfiguration()))
		{
			return true;
		}
		return false;
	}

	// get x position of a specific tile within the grid
	int Grid::getXPosition(tile grid_tile) const
	{
		return std::get<0>(grid_tile);
	}

	// get y position of a specific tile within the grid
	int Grid::getYPosition(tile grid_tile) const
	{
		return std::get<1>(grid_tile);
	}

	// return the configuration of the grid
	std::array<std::array<char, Grid::height>, Grid::width> Grid::getConfiguration() const
	{
		return configuration;
	}
}