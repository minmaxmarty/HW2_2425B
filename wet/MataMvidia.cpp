//
// Created by areg6 on 24/05/2025.
//

#include "MataMvidia.h"

MataMvidia::MataMvidia(const std::string &name, const std::string &producer, const Matrix *frames,
    unsigned int length) {
}

MataMvidia::MataMvidia(const MataMvidia &otherMovie) {
}

MataMvidia & MataMvidia::operator=(const MataMvidia &otherMovie) {
}

Matrix & MataMvidia::operator[](unsigned int index) const {
}

Matrix & MataMvidia::operator[](unsigned int index) {
}

MataMvidia & MataMvidia::operator+=(const MataMvidia &otherMovie) {
}

MataMvidia & MataMvidia::operator+=(const Matrix &matrix) {
}

MataMvidia operator+(const MataMvidia &movie1, const MataMvidia &movie2) {
    MataMvidia movie3(movie1);
    return movie3 += movie2;
}

std::ostream & operator<<(std::ostream &out, const MataMvidia &movie) {
}
