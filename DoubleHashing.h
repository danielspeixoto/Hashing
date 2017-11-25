//
// Created by daniel on 11/22/17.
//

#ifndef HASHING_DOUBLEHASHING_H
#define HASHING_DOUBLEHASHING_H


#include "Hashing.h"

const string DOUBLE_HASHING_FILE = "doubleHashingFile.bin";

class DoubleHashing : public Hashing {
public:

    void insert(Node node) override;
    void read() override;

    int h1(int key);
    int h2(int key);

    explicit DoubleHashing(int size) : Hashing(size, DOUBLE_HASHING_FILE) {}

};


#endif //HASHING_DOUBLEHASHING_H
