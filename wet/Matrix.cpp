//
// Created by areg6 on 24/05/2025.
//

#include "Matrix.h"

unsigned int Matrix::getNumOfRows() const {
    return m_rows;
}

unsigned int Matrix::getNumOfColumns() const {
    return m_columns;
}

Matrix::Matrix(unsigned int rows, unsigned int columns, int initiationNumber) : m_rows(rows), m_columns(columns) {
    m_data = new int[columns * rows];
    for (int i = 0; i < m_columns * m_rows; i++) {
        m_data[i] = initiationNumber;
    }
}

Matrix::~Matrix() {
    delete[] m_data;
}

Matrix::Matrix(const Matrix &otherMatrix) {
    m_columns = otherMatrix.m_columns;
    m_rows = otherMatrix.m_rows;
    m_data = new int[otherMatrix.m_columns * otherMatrix.m_rows];
    for (int i = 0; i < m_columns * m_rows; i++) {
       m_data[i] = otherMatrix.m_data[i];
    }
}

Matrix & Matrix::operator=(const Matrix &otherMatrix) {
    if (this == &otherMatrix) {
        return *this;
    }
    int* dataCopy = new int[otherMatrix.m_columns * otherMatrix.m_rows];
    m_columns = otherMatrix.m_columns;
    m_rows = otherMatrix.m_rows;
    for (int i = 0; i < m_columns * m_rows; i++) {
        dataCopy[i] = otherMatrix.m_data[i];
    }
    delete[] m_data;
    m_data = dataCopy;

    return *this;
}

int & Matrix::operator()(const unsigned int i, const unsigned int j) {
    return m_data[i * m_columns + j];
}

int & Matrix::operator()(const unsigned int i, const unsigned int j) const {
    return this(i,j);
}

Matrix & Matrix::operator+=(const Matrix &otherMatrix) {
    if (checkSizes(*this, otherMatrix)) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    for (unsigned int i = 0; i < m_columns * m_rows; ++i) {
        m_data[i] += otherMatrix.m_data[i];
    }

    return *this;
}

Matrix & Matrix::operator-=(const Matrix &otherMatrix) {
    return *this += -otherMatrix;
}

Matrix & Matrix::operator*=(const Matrix &otherMatrix) {
    if (m_columns != otherMatrix.m_rows) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    Matrix resultMatrix(m_rows, m_columns);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            int sum = 0;
            for (int k = 0; k < m_columns; ++k) {
                sum += *this(i, k) * otherMatrix(k, i);
            }
            resultMatrix(i,j) = sum;
        }
    }

    *this = resultMatrix;
    return *this;
}

Matrix Matrix::operator-() const {
    Matrix negativeMatrix(*this);
    for (unsigned int i = 0; i < m_columns * m_rows; ++i) {
        negativeMatrix.m_data[i] = -m_data[i];
    }

    return negativeMatrix;
}

Matrix & Matrix::operator*=(const int &scalar) {
    for (unsigned int i = 0; i < m_columns * m_rows; ++i) {
        m_data[i] *= scalar;
    }

    return *this;
}

bool Matrix::operator==(const Matrix &otherMatrix) const {
    if (checkSizes(*this, otherMatrix)) {
        return false;
    }

    for (unsigned int i = 0; i < m_columns * m_rows; ++i) {
        if (m_data[i] != otherMatrix.m_data[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &otherMatrix) const {
    return !(*this == otherMatrix);
}

Matrix & Matrix::rotateClockwise() {
    this->transpose();

    // mirroring
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0, k = m_columns - 1; j < k; j++, k--) {
            swap(*this(i, j), *this(j, i));
        }
    }

    return *this;

}

Matrix & Matrix::rotateCounterClockwise() {
    return this->rotateClockwise().rotateClockwise().rotateClockwise();
}

Matrix & Matrix::transpose() {
    Matrix transposedMatrix(m_columns, m_rows);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            transposedMatrix(i, j) = *this(j, i);
        }
    }
    *this = transposedMatrix;
    return *this;

}

double Matrix::CalcFrobeniusNorm(const Matrix &matrix) {
    double sum = 0;
    for (int i = 0; i < matrix.m_columns * matrix.m_rows; ++i) {
        sum += matrix.m_data[i] * matrix.m_data[i];
    }
    return std::sqrt(sum);
}

std::ostream & operator<<(std::ostream& out, const Matrix &matrix) {
    for (int i = 0; i < matrix.getNumOfRows(); ++i) {
        out << BAR;
        for (int j = 0; j < matrix.getNumOfColumns(); ++j) {
            out << matrix(i, j) << BAR;
        }
        out << std::endl;
    }

    return out;
}

Matrix operator+(const Matrix &matrix1, const Matrix &matrix2) {
    Matrix matrix3(matrix1);
    return matrix3 += matrix2;
}

Matrix operator-(const Matrix &matrix1, const Matrix &matrix2) {
    Matrix matrix3(matrix1);
    return (matrix3 -= matrix2);
}

Matrix operator*(const Matrix &matrix1, const Matrix &matrix2) {
    Matrix matrix3(matrix1);
    return matrix3 *= matrix2;
}

Matrix operator*(const Matrix &matrix1, const int &scalar) {
    Matrix matrix2(matrix1);
    return matrix2 *= scalar;
}

// ---------------------- static functions ---------------------- //
bool Matrix::checkSizes(const Matrix &matrix1, const Matrix &matrix2) {
    return matrix1.m_columns != matrix2.m_columns || matrix1.m_rows != matrix2.m_rows;
}

void Matrix::swap(int &x, int &y) {
    const int temp = x;
    x = y;
    y = temp;
}

