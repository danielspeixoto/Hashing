//
// Created by daniel on 11/22/17.
//

#ifndef HASHING_LINKEDHASHING_H
#define HASHING_LINKEDHASHING_H

#include "Hashing.h"
#include <iostream>

using namespace std;


class LinkedHashing : public Hashing {
public:
    const string LINKED_HASHING_FILE = "linkedHashingFile.txt";
    explicit LinkedHashing(int size) : Hashing(size, LINKED_HASHING_FILE) {}

private:
    int position_calculator(int current, int key) override;
};


#endif //HASHING_LINKEDHASHING_H
