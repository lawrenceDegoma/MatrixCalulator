//
// Created by Lawrence Degoma on 2/27/24.
//

#include "Matrix.h"
#include <iostream>
#include <iomanip>

Matrix::Matrix(){}
Matrix::Matrix(int m_row, int m_column){
    row = m_row;
    column = m_column;
    matrix.resize(row, std::vector<int>(column));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

Matrix Matrix::operator+(Matrix const& x){
    if (row != x.row || column != x.column) {
        std::cout << "Error: Dimensions do not match.\n";
        return Matrix();
    }
    else {
        Matrix sum(row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                int num = matrix[i][j] + x.matrix[i][j];
                sum.setElement(i, j, num);
            }
        }
        return sum;
    }
}

Matrix Matrix::operator-(Matrix const& x){
    if (row != x.row || column != x.column) {
        std::cout << "Error: Dimensions do not match.\n";
        return Matrix();
    }
    else {
        Matrix diff(row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                int num = matrix[i][j] - x.matrix[i][j];
                diff.setElement(i, j, num);
            }
        }
        return diff;
    }
}

Matrix Matrix::operator*(Matrix const& x){
    if (column != x.row) {
        std::cout << "Error: Invalid Dimensions";
        return Matrix();
    }
    Matrix mul(row, x.column);
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < x.column; j++) {
            int sum = 0;
            for (int k = 0; k < column; k++){
                sum += matrix[i][k] * x.matrix[k][j];
            }
            mul.setElement(i, j, sum);
        }
    }
    return mul;
}

int Matrix::getRow(){return row;}
int Matrix::getColumn(){return column;}

void Matrix::setRow(int m_row){
    if (m_row < 0){
        throw std::invalid_argument("Error: Invalid row size");
    }
    int oldRow = row;
    row = m_row;
    matrix.resize(row, std::vector<int>(column, 0));
    if (row > oldRow) {
        for (int i=oldRow; i<row; i++)
            matrix[i].resize(column);
    }
}

void Matrix::setColumn(int m_column){
    if (m_column < 0){
        throw std::invalid_argument("Error: Invalid column size\n");
    }
    int oldColumn = column;
    column = m_column;
    for (int i=0; i<row; i++)
        matrix[i].resize(column, 0);
}

int Matrix::setElement(int x, int y, int replace){
    matrix[x][y] = replace;
}

void Matrix::printMatrix() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout<<"\n";
    }
}