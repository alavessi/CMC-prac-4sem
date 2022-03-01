#include "matrix.h"
#include <iostream>

int main()
{
    Matrix m(6, 5);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            m[i][j] = i + j;
        }
    }
    std::cout << "m[1][3] = " << m[1][3] << "\n";
    for (int i = 0; i < 6; i++)
    {
        m[i][3] = 0;
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    const Matrix mc(2, 3, 6);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << mc[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";

    int n = 5;
    double* vals = new double[n];
    for (int i = 0; i < n; i++)
    {
        vals[i] = i + 1;
    }
    Matrix diag = Matrix::diagonal(vals, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << diag[i][j] << " ";
        }
        std::cout << "\n";
    }
    delete [] vals;
    return 0;
}
