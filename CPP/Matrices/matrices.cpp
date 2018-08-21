#include <iostream>

class Matrix
{
private:
    int m_rows;
    int m_cols;
    int **m_array;
    
public:
    Matrix(int row, int col) {
    std::cout << "Enter matrix" << std::endl;
    m_rows = row;
    m_cols = col;
    m_array = new int*[m_rows];
    for (int i = 0; i < m_rows; ++i) {
        m_array[i] = new int[m_cols];
    }
    }

    void fillMatrix() {
        for(int i = 0; i < m_rows; i++) {
            for(int j = 0; j < m_cols; j++) {
        	std::cin >> m_array[i][j];
            }
        }
    }

    void print() {
        for(int i = 0; i < m_rows; i++) {
            for(int j = 0; j < m_cols; j++) {
                std::cout << m_array[i][j];
            }
            std::cout << std::endl;
        }
        
    }
    Matrix operator + (Matrix M)
    { 
        Matrix Sum(m_rows, m_cols);
        for(int i = 0; i < m_rows; i++) {
	    for(int j = 0; j < m_cols; j++)
                {
		     Sum.m_array[i][j] = m_array[i][j] + M.m_array[i][j];
		     std::cout << Sum.m_array[i][j] << " ";
		}
            std::cout << std::endl;
         }
    }
};

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
    return 0;
}
