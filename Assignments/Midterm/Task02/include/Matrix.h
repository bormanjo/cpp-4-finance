#pragma once

#include "std_lib_facilities.h"

class Matrix {
private:
    vector<vector<int>> m_data;
    int m_rows;
    int m_columns;

public:
    Matrix(int rows, int columns);
    Matrix(const vector<vector<int>>& data);

    int rows() const;
    int columns() const;
    int& position(int row, int column);

    Matrix operator+(const Matrix& other);
    Matrix operator*(const Matrix& other);
};

ostream& operator<<(ostream& os, Matrix& m);

