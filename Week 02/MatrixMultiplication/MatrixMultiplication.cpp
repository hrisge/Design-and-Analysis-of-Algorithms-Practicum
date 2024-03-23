#include <iostream>

const constexpr int MAX_SIZE = 20;

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	
	int matrix1[MAX_SIZE][MAX_SIZE];
	int matrix2[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cin >> matrix1[i][j];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
			std::cin >> matrix2[i][j];
	}

	int matrixRes[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			matrixRes[i][j] = 0;
			for (int k = 0; k < m; k++)
			{
				matrixRes[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			std::cout << matrixRes[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
}