#include "Matrix.h"

Matrix::Matrix() : _rows(0), _cols(0), _data(nullptr) {}

Matrix::Matrix(int _dim) : Matrix::Matrix(_dim, _dim) {}

Matrix::Matrix(int _rows, int _cols) : _rows(_rows), _cols(_cols), _data(createMatrix(_rows, _cols)) {}

Matrix::Matrix(const Matrix& other) : _rows(other._rows), _cols(other._cols) {
	_data = createMatrix(_rows, _cols);
	for (int i = 0; i < _rows; ++i) {
		for (int j = 0; j < _cols; ++j) {
			_data[i][j] = other._data[i][j];
		}
	}
}

Matrix::Matrix(Matrix&& other) {
	_rows = other._rows;
	_cols = other._cols;
	_data = other._data;
	other._rows = 0;
	other._cols = 0;
	other._data = nullptr;
}

Matrix::~Matrix() {
	disposeMatrix(_data, _rows);
}

void Matrix::initMatrix() {
	for (int i = 0; i < _rows; ++i) {
		for (int j = 0; j < _cols; ++j) {
			std::cin >> _data[i][j];
		}
	}
}

double Matrix::getValue(int row, int col) {
	return _data[row][col];
}

double Matrix::determinant() {
	if (_rows != _cols) {
		std::cerr << "Error: Matrix is not square" << std::endl;
		exit(1);
	}
	return det(_data, _rows);
}

Matrix Matrix::inverseMatrix() {
	if (_rows != _cols) {
		std::cerr << "Error: Matrix is not square" << std::endl;
		exit(1);
	}
	else if (det(_data, _rows) == 0) {
		std::cerr << "Error: Inverse matrix is undefined - the determinant of source matrix is 0" << std::endl;
		exit(1);
	}

	Matrix inv(_rows);
	inv._data = inverse(_data, _rows);
	return inv;
}

Matrix Matrix::operator*(const Matrix& other) {
	if (_cols != other._rows) {
		std::cerr << "Error: Incompatible matrix dimensions for multiplication" << std::endl;
		exit(1);
	}

	Matrix res(_rows, other._cols);

	for (int i = 0; i < _rows; ++i) {
		for (int j = 0; j < other._cols; ++j) {
			for (int k = 0; k < _cols; ++k) {
				res._data[i][j] += _data[i][k] * other._data[k][j];
			}
		}
	}
	return res;
}

Matrix Matrix::operator*(double coef) {
	Matrix res(_rows, _cols);
	for (int i = 0; i < _rows; ++i) {
		for (int j = 0; j < _cols; ++j) {
			res._data[i][j] = res._data[i][j] * coef;
		}
	}
	return res;
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
	for (int i = 0; i < matrix._rows; ++i) {
		for (int j = 0; j < matrix._cols; ++j) {
			if (std::abs(matrix._data[i][j]) < 1e-10) {
				stream << 0 << " ";
			}
			else {
				stream << matrix._data[i][j] << " ";
			}
		}
		stream << "\n";
	}
	return stream;
}

double** Matrix::createMatrix(int rows, int cols) {
	double** data = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		data[i] = new double[cols] {0};
	}
	return data;
}

void Matrix::disposeMatrix(double**& data, int rows) {
	if (data != nullptr) {
		for (int i = 0; i < rows; ++i) {
			delete[] data[i];
		}
		delete[] data;
		data = nullptr;
	}
}

double** Matrix::minor(double** data, int n, int row, int col) {
	double** res = createMatrix(n - 1, n - 1);
	for (int i = 0, ri = 0; i < n; ++i)
	{
		if (i == row) continue;
		for (int j = 0, rj = 0; j < n; ++j)
		{
			if (j == col) continue;
			res[ri][rj] = data[i][j];
			++rj;
		}
		++ri;
	}
	return res;
}

double Matrix::cofactor(double** data, int n, int row, int col) {
	double** mnr = minor(data, n, row, col);
	double res = det(mnr, n - 1) * ((row + col) % 2 == 0 ? 1 : -1);
	disposeMatrix(mnr, n - 1);
	return res;
}

double Matrix::det(double** data, int n) {
	if (n == 1) {
		return data[0][0];
	}

	double res = 0;

	for (int i = 0; i < n; ++i) {
		res += data[0][i] * cofactor(data, n, 0, i);
	}

	return res;
}

double** Matrix::inverse(double** data, int n) {
	double** inv = createMatrix(n, n);
	double res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			inv[i][j] = cofactor(data, n, j, i) / det(data, n);
		}
	}
	return inv;
}

void showSystem(Matrix matr, Matrix vect, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			std::cout << "(" << matr.getValue(i, j) << ") * " << "x" << j + 1 << " + ";
		}
		std::cout << "(" << matr.getValue(i, n - 1) << ") * " << "x" << n << " = " << vect.getValue(i, 0) << std::endl;
	}
}

void showSolution(Matrix sol, int n) {
	std::cout << "X = (";
	for (int i = 0; i < n - 1; ++i) {
		std::cout << sol.getValue(i, 0) << ", ";
	}
	std::cout << sol.getValue(n - 1, 0) << ")" << std::endl;
}

void writeLatexSystem(std::ofstream& file, Matrix matr, Matrix vect, int n) {
	file << "\\[\n\\begin{cases}\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			file << matr.getValue(i, j) << "x_{" << j + 1 << "} + ";
		}
		file << matr.getValue(i, n - 1) << "x_{" << n << "} = " << vect.getValue(i, 0) << " \\\\\n";
	}
	file << "\\end{cases}\n\\]\n";
}

void writeLatexMatrix(std::ofstream& file, std::string name, Matrix matr, int _rows, int _cols) {
	file << "\\[\n" << name << " = \\begin{pmatrix}\n";
	for (int i = 0; i < _rows; ++i) {
		for (int j = 0; j < _cols; ++j) {
			file << matr.getValue(i, j);
			if (j < _cols - 1) {
				file << " & ";
			}
		}
		if (i < _rows - 1) {
			file << " \\\\\n";
		}
	}
	file << "\n\\end{pmatrix}\n\\]\n\n";
}

void writeLatexFile(std::ofstream& file, Matrix matr, Matrix vect, Matrix inv, Matrix sol, int n) {
	file << "\\documentclass{article}\n";
	file << "\\usepackage{amsmath}\n";
	file << "\\begin{document}\n";
	file << "\\section*{Solution of System of Linear Algebraic Equations}\n";

	writeLatexSystem(file, matr, vect, n);
	writeLatexMatrix(file, "A", matr, n, n);
	writeLatexMatrix(file, "B", vect, n, 1);
	writeLatexMatrix(file, "A^{-1}", inv, n, n);
	writeLatexMatrix(file, "X", sol, n, 1);
	file << "\\end{document}\n";

	file.close();
}
