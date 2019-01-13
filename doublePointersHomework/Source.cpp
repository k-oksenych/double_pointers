#include <ctime>
#include <iostream>

using namespace std;

//Function creates a two-dimensional array of specified size

int** createArray(const int rows, const int columns)
{
	int** array = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		array[i] = new int[columns];
	}

	return array;
}

//Function deletes a two-dimensional array
//test

void deleteArray(int** array, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] array[i];
	}
	delete[] array;
}

//Function fills a two-dimensional array with random numbers

int** fillArray(int** array, const int rows, const int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			array[i][j] = rand() % 10;
		}
	}

	return array;
}

//Function outuputs a two-dimensional dynamic array to the console

void printArray(int** const array, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
}

//Function adds a row(one-dimensional array) to the end of two-dimensional array

int** addNewRowEnd(int** const array, int& rows, const int columns)
{
	int** temp = new int*[rows + 1];
	for (int i = 0; i < rows; ++i)
	{
		temp[i] = array[i];
	}

	temp[rows] = new int[columns];

	delete[] array;

	++rows;

	return temp;
}

//Function adds a row(one_dimensional array) to the beginning of two-dimensional array

int** addNewRowBeginning(int** const array, int& rows, const int columns)
{
	int** temp = new int*[rows + 1];

	for (int i = 1; i <= rows; ++i)
	{
		temp[i] = array[i - 1];
	}

	temp[0] = new int[columns];

	delete[] array;

	++rows;

	return temp;
}

//Function inserts a row in specified position of two-dimensional array

int** insertNewRow(int** const array, int& rows, const int columns, int value)
{
	int** temp = new int*[rows + 1];

	for (int i = 0; i < value; ++i)
	{
		temp[i] = array[i];
	}

	for (int i = value + 1; i <= rows; ++i)
	{
		temp[i] = array[i - 1];
	}

	temp[value] = new int[columns];

	delete[] array;

	++rows;

	return temp;
}

//Function deletes a row of two-dimensional array at the specified number

int** deleteRow(int** const array, int& rows, const int columns, int value)
{
	int** temp = new int*[rows - 1];

	for (int i = 0; i < value; ++i)
	{
		temp[i] = array[i];
	}

	for (int i = value; i < rows; ++i)
	{
		temp[i] = array[i + 1];
	}

	delete[] array;

	--rows;

	return temp;
}

//Function adds a column(one-dimensional array) to the end of two-dimensional array

int** addColumnEnd(int** const array, const int rows, int& columns)
{
	int** temp = new int*[rows];

	for (int i = 0; i < rows; ++i)
	{
		temp[i] = new int[columns + 1];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			temp[i][j] = array[i][j];
		}
	}

	delete[] array;

	++columns;

	return temp;
}

//Function adds a column to the beginning of two-dimensional array

int** addColumnBeginning(int** const array, const int rows, int& columns)
{
	int** temp = new int*[rows];

	for (int i = 0; i < rows; ++i)
	{
		temp[i] = new int[columns + 1];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 1; j <= columns; ++j)
		{
			temp[i][j] = array[i][j - 1];
		}
	}

	delete[] array;

	++columns;

	return temp;
}

//Function inserts a column in specified position of two-dimensional array

int** insertColumn(int** const array, const int rows, int& columns, int value)
{
	int** temp = new int*[rows];

	for (int i = 0; i < rows; ++i)
	{
		temp[i] = new int[columns + 1];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < value; ++j)
		{
			temp[i][j] = array[i][j];
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = value + 1; j <= columns; ++j)
		{
			temp[i][j] = array[i][j - 1];
		}
	}

	delete[] array;

	++columns;

	return temp;
}

//Function deletes a column of two-dimensional array at the specified number

int** deleteColumn(int** const array, const int rows, int& columns, int value)
{
	int** temp = new int*[rows];

	for (int i = 0; i < rows; ++i)
	{
		temp[i] = new int[columns - 1];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < value; ++j)
		{
			temp[i][j] = array[i][j];
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = value; j < columns; ++j)
		{
			temp[i][j] = array[i][j + 1];
		}
	}

	delete[] array;

	--columns;

	return temp;
}

//Function transforms two-dimensional array into one-dimensional array

int* multiToSingle(int** array, int rows, int columns)
{
	int size = rows * columns;
	
	int* temp = new int[size];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			temp[i * columns + j] = array[i][j];
		}
	}

	delete[] array;

	return temp;
}

//Function transforms one-dimensional array into two-dimensional array

int** singleToMulti(int* array, int size, int rows, int columns)
{
	int** temp = nullptr;
	if (size > rows * columns)
	{
		cout << "Error" << endl;
	}
	else
	{
		temp = new int*[rows];
		for (int i = 0; i < rows; ++i)
		{
			temp[i] = new int[columns];
		}

		int iterator = 0;

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				if (iterator >= size)
				{
					temp[i][j] = 0;
				}
				else
				{
					temp[i][j] = array[iterator];
					iterator++;
				}
			}
		}
	}

	delete[] array;

	return temp;
}

int main()
{
	srand(time(nullptr));

	//int rows = 0;
	//int columns = 0;
	//int value = 0;
	//cout << "Enter rows amount: ";
	//cin >> rows;
	//cout << "Enter columns amount: ";
	//cin >> columns;
	//cout << "Enter a position: ";
	//cin >> value;

	//int** array = createArray(rows, columns);
	//array = fillArray(array, rows, columns);
	//printArray(array, rows, columns);

	//cout << endl << endl;

	//int* array2 = multiToSingle(array, rows, columns);
	
	//for (int i = value - 1; i < rows; ++i)
	//{
	//	array[i][value] = rand() % 10;
	//}

	/*printArray(array, rows, columns);*/

	//for (int i = 0; i < (rows*columns); ++i)
	//{
	//	cout << array2[i] << ' ';
	//}
	//cout << endl;

	int size = 0;
	cout << "Enter size: ";
	cin >> size;

	int* array = new int[size];

	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 10;
	}

	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << ' ';
	}
	cout << endl;

	int rows = 0;
	int columns = 0;
	cout << "Enter rows amount: ";
	cin >> rows;
	cout << "Enter columns amount: ";
	cin >> columns;

	int** array2 = singleToMulti(array, size, rows, columns);

	if (array2 != nullptr)
	{
		printArray(array2, rows, columns);
	}
	
}