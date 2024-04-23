#include <iostream>
#include <vector>

#ifndef VECTORASSIGNMENT_MATRIX_H
#define VECTORASSIGNMENT_MATRIX_H


class Matrix{
public:
    Matrix();
    Matrix(int, int);
    Matrix operator+(Matrix const&);
    Matrix operator-(Matrix const&);
    Matrix operator*(Matrix const&);
    int getRow();
    int getColumn();
    void setRow(int);
    void setColumn(int);
    int setElement(int, int, int);
    void printMatrix();
private:
    int column;
    int row;
    std::vector<std::vector<int>> matrix;
};

#endif
