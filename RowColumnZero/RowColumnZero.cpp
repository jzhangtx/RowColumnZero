// RowColumnZero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void ZeroRow(std::vector<std::vector<int>>& matrix, int row)
{
    for (size_t j = 0; j < matrix[row].size(); ++j)
        matrix[row][j] = 0;
}

void ZeroCol(std::vector<std::vector<int>>& matrix, int col)
{
    for (size_t i = 0; i < matrix.size(); ++i)
        matrix[i][col] = 0;
}

void SetRowColumnZeroes(std::vector<std::vector<int>>& matrix)
{
	// if a row a col has been set to 0, it may affect
	//  0 checking of the cell that has been changed.
	//  so, we'd like to copy the matrix
	std::vector<std::vector<int>> matrixCopy = matrix;

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrixCopy[i][j] == 0)
            {
                ZeroRow(matrix, static_cast<int>(i));
                ZeroCol(matrix, static_cast<int>(j));
            }
        }
    }
}

int main()
{
	while (true)
	{
		int countX = 0, countY = 0;
		std::cout << "Matrix size: ";
		std::cin >> countY >> countX;
		if (countX == 0 || countY == 0)
			break;

		std::vector<std::vector<int>> vec(countY);
		for (int i = 0; i < countY; ++i)
		{
			vec[i].resize(countX);
			std::cout << "The number array: ";
			for (int j = 0; j < countX; ++j)
				std::cin >> vec[i][j];
		}

		SetRowColumnZeroes(vec);
		std::cout << "Rotated Matrix: " << std::endl;
		for (int i = 0; i < countY; ++i)
		{
			std::cout << "{ ";
			for (int j = 0; j < countX; ++j)
			{
				if (j != 0)
					std::cout << ", ";
				std::cout << vec[i][j];
			}
			std::cout << " }";
			if (i != countY - 1)
				std::cout << ",";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}
