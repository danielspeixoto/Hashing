//
// Created by daniel on 11/22/17.
//

#include <iostream>
#include <fstream>
#include <tuple>
#include "DoubleHashing.h"

using namespace std;

void DoubleHashing::read() {
    for(int i = 0; i < this->size; i++) {
        cout << i << ": ";
        Node node = this->get_item(i);
        if(node.is_empty) {
            cout << Node::empty << endl;
        } else {
            cout << node.hashingFormat() << endl;
        }
    }
}

int DoubleHashing::h1(int key) {
    return key % size;
}

int DoubleHashing::h2(int key) {
    int answer = key / size;
    if(answer == 0) {
        return 1;
    }
    return answer;
}

int DoubleHashing::position_calculator(int current, int key) {
    if(current == -1) {
        return h1(key);
    } else {
        return (current + h2(key)) % size;
    }
}
