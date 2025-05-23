//
// Created by areg6 on 24/05/2025.
//

#ifndef MATAMVIDIA_H
#define MATAMVIDIA_H

#include "Matrix.h"
#include <string>

class MataMvidia {
    unsigned int m_length;
    Matrix* m_frames; // TODO: make linked list
    std::string m_name;
    std::string m_producer;

public:
    MataMvidia(const std::string& name, const std::string& producer, const Matrix* frames, unsigned int length);
    MataMvidia(const MataMvidia& otherMovie);
    MataMvidia& operator=(const MataMvidia& otherMovie);

    Matrix& operator[](unsigned int index) const; // read-only
    Matrix& operator[](unsigned int index);
    MataMvidia& operator+=(const MataMvidia& otherMovie);
    MataMvidia& operator+=(const Matrix& matrix);

};

MataMvidia operator+(const MataMvidia& movie1, const MataMvidia& movie2);
std::ostream& operator<<(std::ostream& out, const MataMvidia& movie);


#endif //MATAMVIDIA_H
