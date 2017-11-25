//
// Created by daniel on 11/22/17.
//

#ifndef HASHING_HASHING_H
#define HASHING_HASHING_H

#include <iostream>
#include "Node.h"

using namespace std;

class Hashing {
    public:
        int size;
        string filepath;
        explicit Hashing(int size, string filepath);
        virtual void insert(Node node) {};
        virtual void read() {};
        static void printFile(string path);
        void setup();
        Node getItem(int position);
        void setItem(Node node, int position);
};


#endif //HASHING_HASHING_H
