#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int m_rows;
    int m_cols;
    int **m_array;
public:
    Matrix(int row, int col);
    Matrix(const Matrix &m);
    ~Matrix();
    void fillMatrix();
    void print();
    Matrix operator + (const Matrix& M);
};

#endif
