#include <iostream>
//#include "matrices.cpp"
#include "matrices.h"
int main()
{
    int rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    int columns;
    std::cout << "Enter the number of columns of the matrices: ";
    std::cin >> columns;

    Matrix M1(rows, columns);
    M1.fillMatrix();
    Matrix M2(rows, columns);
    M2.fillMatrix();

    Matrix M3 = M1 + M2;
    M3.print();
    return 0;
}
      
