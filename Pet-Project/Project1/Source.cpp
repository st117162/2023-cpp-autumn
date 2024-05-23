#include "Matrix.h"

int main() {
    std::cout << "---------------------------------------------------\n";
    std::cout << "Welcome to the Matrix Equation Solver Program!\n";
    std::cout << "Thank you for using our program.\n";
    std::cout << "---------------------------------------------------\n\n";

    int n;
    std::cout << "Please, enter the number of equations: ";
    std::cin >> n;

    Matrix a(n);
    Matrix b(n, 1);

    std::cout << "\nPlease, enter the coefficients of the matrix A (row by row):\n";
    a.initMatrix();

    std::cout << "\nPlease, enter the vector of free terms (B):\n";
    b.initMatrix();

    Matrix a_inv = a.inverseMatrix();
    Matrix x = a_inv * b;

    std::string filename = "solution.tex";
    std::ofstream latexFile(filename);

    writeLatexFile(latexFile, a, b, a.inverseMatrix(), x, n);

    std::cout << "\nYou can check the solution in " << filename << "\n";
    std::cout << "Goodbye!\n";

    return EXIT_SUCCESS;
}
