//
// Created by areg6 on 24/05/2025.
//

#ifndef MATAMVIDIA_H
#define MATAMVIDIA_H

#include "Matrix.h"
#include <string>

const std::string EMPTY = "";

class MataMvidia {
    unsigned int m_length;
    Matrix* m_frames;
    std::string m_name;
    std::string m_producer;

public:
    const std::string& getName() const;
    const std::string& getProducer() const;

    unsigned int getLength() const;

    ~MataMvidia(); 
    MataMvidia(const std::string& name, const std::string& producer, const Matrix* frames, unsigned int length);
    MataMvidia(const MataMvidia& otherMovie);
    MataMvidia& operator=(const MataMvidia& otherMovie);


    Matrix& operator[](unsigned int index);
    Matrix& operator[](unsigned int index) const; // read-only
    MataMvidia& operator+=(const MataMvidia& otherMovie);
    MataMvidia& operator+=(const Matrix& matrix);

};

MataMvidia operator+(const MataMvidia& movie1, const MataMvidia& movie2);
std::ostream& operator<<(std::ostream& out, const MataMvidia& movie);


#endif //MATAMVIDIA_H
