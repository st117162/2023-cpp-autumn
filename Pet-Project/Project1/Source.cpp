#include "Matrix.h"
#include <cstdlib>

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

    std::cout << "\nPlease, enter the coefficients of the matrix A:\n";
    a.initMatrix();

    std::cout << "\nPlease, enter the coefficients of the vector B:\n";
    b.initMatrix();

    Matrix a_inv = a.inverseMatrix();
    Matrix x = a_inv * b;

    std::string filename = "solution.tex";
    std::ofstream latexFile(filename);

    writeLatexFile(latexFile, a, b, a.inverseMatrix(), x, n);
    std::cout << "\nYou can check the solution in " << filename << "\n\n\n";

    std::string command = "pdflatex " + filename;
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "\n\nPDF file generated successfully.\n";
    }
    else {
        std::cout << "\n\nError occurred while generating PDF file.\n";
    }

    std::cout << "\n\nGoodbye!\n";

    return EXIT_SUCCESS;
}