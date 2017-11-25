//
// Created by daniel on 11/22/17.
//

#include <cstdio>
#include <string>
#include <fstream>
#include "Hashing.h"
#include <iostream>
#include <bits/types/FILE.h>

using namespace std;

void Hashing::writeToFile(string content) {

}

void Hashing::read() {
    printFile(Hashing::filepath);
}

void Hashing::printFile(string path) {
    ifstream stream(path);
    if(stream.is_open()) {
        cout << stream.rdbuf();
    }
}

Hashing::Hashing(int size, string filepath) {
    this->size = size;
    this->filepath = filepath;
    setup();
}

void Hashing::setup() {
    // Check if file exists
    if(!ifstream(filepath)) {
        fstream file(filepath, ios::binary | ios::app);
        if(file.is_open()) {
            Node empty = Node(0, "empty", 0);
            empty.isEmpty = true;
            file.write((char*) &empty, sizeof(Node));
            file.close();
        }
    }
}
