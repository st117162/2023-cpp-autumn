#pragma once
#include <iostream>
#include <fstream>

class Matrix {
public:
	Matrix();
	Matrix(int _dim);
	Matrix(int _rows, int _cols);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other);
	~Matrix();
	void initMatrix();
	double getValue(int row, int col);
	double determinant();
	Matrix inverseMatrix();
	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
	Matrix operator*(const Matrix& other);
	Matrix operator*(double coef);

private:
	int _rows;
	int _cols;
	double** _data;
	double** createMatrix(int rows, int cols);
	void disposeMatrix(double**& data, int rows);
	double** minor(double** data, int n, int row, int col);
	double cofactor(double** data, int n, int row, int col);
	double det(double** data, int n);
	double** inverse(double** data, int n);
};

void showSystem(Matrix matr, Matrix vect, int n);
void showSolution(Matrix sol, int n);
void writeLatexSystem(std::ofstream& file, Matrix matr, Matrix vect, int n);
void writeLatexMatrix(std::ofstream& file, std::string name, Matrix matr, int _rows, int _cols);
void writeLatexFile(std::ofstream& file, Matrix matr, Matrix vect, Matrix inv, Matrix sol, int n);
