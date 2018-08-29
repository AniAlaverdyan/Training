#include <iostream>
#include "matrices.h"

Matrix :: Matrix(int row, int col) {
    std::cout << "Constructor called." << std::endl;
    std::cout << "Create matrix" << std::endl;
    m_rows = row;
    m_cols = col;
    m_array = new int*[m_rows];
    for (int i = 0; i < m_rows; ++i) {
        m_array[i] = new int[m_cols];
    }
}

Matrix :: Matrix(const Matrix &m) {
    std::cout << "In a copy constructor." << std::endl;
}

Matrix :: ~Matrix() {
    std::cout << "Destructor called." << std::endl;
    for (int i = 0; i < m_rows; ++i) {
        delete m_array[i];
    }
    delete m_array;
}

void Matrix :: fillMatrix() {
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < m_cols; j++) {
            std::cin >> m_array[i][j];
        }
    }
}

void Matrix :: print() {
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < m_cols; j++) {
            std::cout << m_array[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

Matrix Matrix :: operator + (const Matrix& M) {
    Matrix Sum(m_rows, m_cols);
    std::cout << "Sum of Matrices" << std::endl;
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < m_cols; j++) {
            Sum.m_array[i][j] = m_array[i][j] + M.m_array[i][j];
        }
    }
    return Sum;
}

