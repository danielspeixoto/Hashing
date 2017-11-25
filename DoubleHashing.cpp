//
// Created by daniel on 11/22/17.
//

#include <iostream>
#include "DoubleHashing.h"

using namespace std;

void DoubleHashing::insert(Node node) {
//    string filepath = getFilepath();
//    FILE* pFile = fopen(getFilepath().c_str(), "wb");
//    const char *buffer = content.c_str();
//    fwrite (buffer , sizeof(char), sizeof(buffer), pFile);
//    fclose (pFile);
}

int DoubleHashing::h1(int key) {
    return key % DoubleHashing::size;
}

int DoubleHashing::h2(int key) {
    int answer = key / this->size;
    if(answer == 0) {
        return 1;
    }
    return answer;
}

