//
// Created by daniel on 11/22/17.
//

#include <cstdio>
#include <string>
#include <fstream>
#include "Hashing.h"
#include <iostream>
#include <bits/types/FILE.h>
#include <cstring>

using namespace std;

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
            char name[20];
            strcpy(name, Node::empty);
            Node empty = Node(0, name, 0);
            empty.isEmpty = true;
            for(int i = 0; i < this->size; i++) {
                Node empty = Node(i, name, i);
                empty.isEmpty = true;
                file.write((char*) &empty, sizeof(Node));
            }
            file.close();
        }
    }
}

Node Hashing::getItem(int position) {
    ifstream file(filepath, ios::binary);
    Node* searched = (Node*) malloc(sizeof(Node));
    if(file.is_open()) {
        file.seekg(sizeof(Node) * position, ios_base::beg);
        file.read((char*)searched, sizeof(Node));
        file.close();
    }
    return *searched;
}

void Hashing::setItem(Node node, int position) {
    fstream file(filepath, ios::binary|ios::in|ios::out);
    if(file.is_open()) {
        file.seekp(sizeof(Node) * position, ios_base::beg);
        file.write((char*) &node, sizeof(Node));
        file.close();
    }
}