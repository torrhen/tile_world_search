#include "../include/Grid.h"

#include <iostream>
#include <array>
#include <exception>
#include <iterator>

namespace TileSearch
{
	Grid::Grid()
	{

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

	StartGrid::StartGrid()
	{
		clear();
		// set the starting positions of each tile
		P = std::make_pair(3, 0);
		A = std::make_pair(0, 0);
		B = std::make_pair(1, 0);
		C = std::make_pair(2, 0);
		// build the start grid
		build();
	}

	StartGrid::~StartGrid()
	{

	}

	GoalGrid::GoalGrid()
	{
		clear();
		// set the goal positions of each tile
		P = std::make_pair(3, 0);
		A = std::make_pair(1, 2);
		B = std::make_pair(1, 1);
		C = std::make_pair(1, 0);
		// build the goal grid
		build();
	}

	GoalGrid::~GoalGrid()
	{

	}

	StandardGrid::StandardGrid(const Grid& other)
	{
		clear();
		// copy the positions of each tile
		P = other.getP();
		A = other.getA();
		B = other.getB();
		C = other.getC();
		// build the grid	
		build();
	}

	Grid& StandardGrid::operator=(const Grid& other)
	{
		// copy and swap
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

	// // compare configuration between grids
	// bool StandardGrid::isIdenticalTo(const Grid& other)
	// {
	// 	if (this->configuration == other.configuration)
	// 	{
	// 		return true;
	// 	}
	// 	return false;
	// }
}