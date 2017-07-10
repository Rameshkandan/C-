#include<iostream>
int main()
{
	int i, j;
	const int n = 3;
	const int m = 3;
	int *matrix = new int[n*n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <m; j++)
		{
			matrix[n*i + j] = 0;
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = i; j <m; j++)
		{
			matrix[n*i + j] = i;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			std::cout << matrix[n*i + j] << "\t";

		}
		std::cout << "\n";
	}
	delete [] matrix;
	system("pause");
	return 0;
}