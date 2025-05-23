//
// Created by areg6 on 24/05/2025.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>


class Matrix {
    int* data;
    unsigned int m_columns;
    unsigned int m_rows;

public:

    // constructors and assignment
    Matrix() : data(nullptr), m_columns(0), m_rows(0) {}
    Matrix(unsigned int columns, unsigned int rows, int initiationNumber = 0);
    Matrix(const Matrix& otherMatrix);
    Matrix& operator=(const Matrix& otherMatrix);

    // indexing and assignments per index
    int& operator()(unsigned int i, unsigned int j) const; // read-only
    int& operator()(unsigned int i, unsigned int j);

    // math
    Matrix& operator+=(const Matrix& otherMatrix);
    Matrix& operator-=(const Matrix& otherMatrix);
    Matrix& operator*=(const Matrix& otherMatrix);
    Matrix& operator-();
    Matrix& operator*=(const int& scalar);

    // bool
    bool operator==(const Matrix& otherMatrix) const;
    bool operator!=(const Matrix& otherMatrix) const;

    // matrix manipulations
    Matrix& rotateClockwise();
    Matrix& rotateCounterClockwise();
    Matrix& transpose();

    // static
    static unsigned int CalcFrobeniusNorm(const Matrix& matrix);

};

std::ostream& operator<<(std::ostream out, const Matrix& matrix); // return ostream& for chain ability
Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);
Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);
Matrix operator*(const Matrix& matrix1, const Matrix& matrix2);
Matrix operator*(const Matrix& matrix1, const int& scalar);



#endif //MATRIX_H
