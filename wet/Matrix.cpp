//
// Created by areg6 on 24/05/2025.
//

#include "Matrix.h"

Matrix::Matrix(unsigned int columns, unsigned int rows, int initiationNumber) {
}

Matrix::Matrix(const Matrix &otherMatrix) {
}

Matrix & Matrix::operator=(const Matrix &otherMatrix) {
}

int & Matrix::operator()(unsigned int i, unsigned int j) const {
}

int & Matrix::operator()(unsigned int i, unsigned int j) {
}

Matrix & Matrix::operator+=(const Matrix &otherMatrix) {
}

Matrix & Matrix::operator-=(const Matrix &otherMatrix) {
}

Matrix & Matrix::operator*=(const Matrix &otherMatrix) {
}

Matrix & Matrix::operator-() {
}

Matrix & Matrix::operator*=(const int &scalar) {
}

bool Matrix::operator==(const Matrix &otherMatrix) const {
}

bool Matrix::operator!=(const Matrix &otherMatrix) const {
}

Matrix & Matrix::rotateClockwise() {
}

Matrix & Matrix::rotateCounterClockwise() {
}

Matrix & Matrix::transpose() {
}

unsigned int Matrix::CalcFrobeniusNorm(const Matrix &matrix) {
}

std::ostream & operator<<(std::ostream out, const Matrix &matrix) {
}

Matrix operator+(const Matrix &matrix1, const Matrix &matrix2) {
    Matrix matrix3(matrix1);
    return matrix3 += matrix2;
}

Matrix operator-(const Matrix &matrix1, const Matrix &matrix2) {
    Matrix matrix3(matrix1);
    return matrix3 -= matrix2;
}

Matrix operator*(const Matrix &matrix1, const Matrix &matrix2) {
    Matrix matrix3(matrix1);
    return matrix3 *= matrix2;
}

Matrix operator*(const Matrix &matrix1, const int &scalar) {
    Matrix matrix2(matrix1);
    return matrix2 *= scalar;
}
