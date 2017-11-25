//
// Created by daniel on 11/22/17.
//

#include <iostream>
#include <fstream>
#include "DoubleHashing.h"

using namespace std;

void DoubleHashing::insert(Node node) {
    int position = this->h1(node.key);
    int counter = 0;
    while(!this->getItem(position).isEmpty) {
        position = (position + this->h2(node.key)) % this->size;
        counter++;
        if(counter > this->size) {
            cout << "Node cannot be inserted";
            return;
        }
    }
    setItem(node, position);
}

void DoubleHashing::read() {
    for(int i = 0; i < this->size; i++) {
        cout << i << ": ";
        Node node = this->getItem(i);
        if(node.isEmpty) {
            cout << Node::empty << endl;
        } else {
            cout << node.hashingFormat() << endl;
        }
    }
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

