//
// Created by daniel on 11/23/17.
//

#ifndef HASHING_NODE_H
#define HASHING_NODE_H

#include <iostream>

using namespace std;

class Node {
    public:
        int key;
        char* name;
        int age;
        int next = -1;
        int isEmpty = false;
        Node(int key, char* name, int age);
        string hashingFormat();
};


#endif //HASHING_NODE_H
