#include <iostream>
#include <math.h>
using namespace std;

void print(int **matrix, int r, int c) 
{
	cout << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void Add(int **A, int **B, int row, int col)
{
	int **sum;
	sum = new int*[row];
	for (int i = 0; i < row; i++)
	{
		sum[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum[i][j] = 0;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum[i][j] = A[i][j] + B[i][j];
		}
	}

	print(sum, row, col);
}
void Subtract(int **A, int **B, int row, int col)
{
	int **sum;
	sum = new int*[row];
	for (int i = 0; i < row; i++)
	{
		sum[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum[i][j] = 0;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum[i][j] = A[i][j] - B[i][j];
		}
	}

	print(sum, row, col);
}
void Multilply(int **A, int rowA, int colA, int **B, int rowB, int colB)
{
	int **product;
	product = new int*[rowA];
	for (int i = 0; i < rowA; i++)
	{
		product[i] = new int[colB];
	}

	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			product[i][j] = 0;
		}
	}

	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			for (int k = 0; k < colA; k++)
			{
				product[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	print(product, rowA, colB);
}	
void Inverse(int **A, int row, int col)
{	
	double det = 0;
	for (int i = 0; i < 3; i++)
		det = det + (A[0][i] * (A[1][(i + 1) % 3] * A[2][(i + 2) % 3] - A[1][(i + 2) % 3] * A[2][(i + 1) % 3]));

	cout << "\n\ndeterminant: " << det;

	double **inv;
	inv = new double*[row];
	for (int i = 0; i < row; i++)
	{
		inv[i] = new double[col];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			static_cast<double>(A[i][j]);
		}
	}
	

	cout << "\n\nInverse of matrix is: \n";
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			inv[i][j] = ((A[(j + 1) % 3][(i + 1) % 3] * A[(j + 2) % 3][(i + 2) % 3]) - (A[(j + 1) % 3][(i + 2) % 3] * A[(j + 2) % 3][(i + 1) % 3])) / det ;
		}
		
	}
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << inv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}




int main()
{
	int row, col;
	int **matrixA;

	cout << "Please enter row size for matrix A : ";
	cin >> row;

	cout << "Please enter column size for matrix A: ";
	cin >> col;
	// create matrix A
	matrixA = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrixA[i] = new int[col];
	}
	
	cout << "Please enter elements of matrix 1 " << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrixA[i][j];
		}
	}

	//?????????????????????????????? MATRIX B ???????????????????????????????????????????????????????
	int rowB, colB;
	int **matrixB;

	cout << "Please enter row size for matrix B : ";
	cin >> rowB;

	cout << "Please enter column size for matrix B : ";
	cin >> colB;
	// create matrix B
	matrixB = new int*[rowB];
	for (int i = 0; i < rowB; i++)
	{
		matrixB[i] = new int[colB];
	}

	//populate matrix B
	for (int i = 0; i < rowB; i++)
	{
		for (int j = 0; j < colB ; j++)
		{
			cin >> matrixB[i][j];
		}
	}
	cout << endl << endl;

	cout << "Matrix A " << endl;
	print(matrixA, row, col);
	cout << "Matrix B " << endl;
	print(matrixB, rowB, colB);

	// menue of options
	int operation; 
	cout << "please select an operation" << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Inverse" << endl;
	cin >> operation;

	switch (operation)
	{
	case 1:
		if (row != rowB || col != colB)
		{
			cout << "Cannot ADD as Dimensions are not same" << endl;
			break;
		}
		else
		{
			Add(matrixA, matrixB, row, col);
			break;
		}
	case 2:
		if (row != rowB || col != colB)
		{
			cout << "Cannot Subtract as Dimensions are not same" << endl;
			break;
		}
		else
		{
			Subtract(matrixA, matrixB, row, col);
			break;
		}
	case 3:
		if (col != rowB)
		{
			cout << "Dimensions are not correct for multiplication" << endl;
			break;
		}
		else
		{
			Multilply(matrixA, row, col, matrixB, rowB, colB);
			break;
		}
	case 4:
		if (row > 3 || rowB > 3)
		{
			cout << "Sorry,I dont know how to find inverse of this!" << endl;
			break;
		}
		else
		{
			Inverse(matrixA, row, col);
			Inverse(matrixB, rowB, colB);
			break;
		}
		
	default:
		cout << "Invalid option!" << endl;
		break;
	}

	for (int i = 0; i < row; ++i) {
		delete[] matrixA[i];
	}
	delete[] matrixA;

	for (int i = 0; i < rowB; ++i) {
		delete[] matrixB[i];
	}
	delete[] matrixB;

	system("pause");
}