#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
    : m_rows{ rows }
    , m_columns{ columns }
{
    m_data = vector<vector<int>>(m_rows, vector<int>(m_columns));
}

Matrix::Matrix(const vector<vector<int>>& data)
{
    m_data = data;
    m_rows = m_data.size();
    m_columns = m_data[0].size();
}

int Matrix::rows() const
{
    return m_rows;
}

int Matrix::columns() const
{
    return m_columns;
}

int& Matrix::position(int row, int column)
{
    if (0 > row && m_rows <= row && 0 > column && m_columns <= column)
        error("out of bounds");

    return m_data[row][column];
}

ostream& operator<<(ostream& os, Matrix& m)
{
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.columns(); ++j) {
            os << m.position(i, j) << '\t';
        }
        if (i < m.rows() - 1) {
            os << '\n';
        }
    }

    return os;
}

Matrix Matrix::operator+(const Matrix& other){
    if(this->m_columns != other.m_columns && this->m_rows != other.m_rows){
        error("Matrix dimensions do not match");
    }

    Matrix result = Matrix(this->m_rows, this->m_columns);

    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < this->m_columns; j++){
            result.m_data[i][j] = this->m_data[i][j] + other.m_data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other){
    if(this->m_rows != other.m_columns && this->m_columns != other.m_rows){
        error("Matrix dimensions do not match");
    }

    int res_element = 0;
    Matrix result = Matrix(this->m_rows, other.m_columns);

    for(int i = 0; i < this->m_rows; i++){
        for(int j = 0; j < other.m_columns; j++){

            res_element = 0;

            for(int z = 0; z < this->columns(); z++){
                res_element += this->m_data[i][z] * other.m_data[z][j];
            }

            result.m_data[i][j] = res_element;
        }
    }

    return result;
}
