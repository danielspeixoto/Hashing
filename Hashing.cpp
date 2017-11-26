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
#include <tuple>
#include <functional>

using namespace std;

Hashing::Hashing(int size, string filepath) {
    this->size = size;
    this->filepath = filepath;
    setup();
}

// Main Functions
Node Hashing::search(int key) {
    return get<1>(search(key, this->is_same_key));
}

//TODO Change calculator
void Hashing::insert(Node node) {
    int position = get<0>(search(node.key,
                                 this->not_empty_node,
                                 &Hashing::insert_calculator));
    if(position != -1) {
        set_item(node, position);
    }
}

double Hashing::time_spent() {
    int amount = 0;
    Node node = Node::empty_node();
    int items_count = 0;
    for(int i = 0; i < size; i++) {
        node = get_item(i);
        if(!node.is_empty) {
            items_count++;
            amount += time_spent(node.key);
        }
    }
    return amount/(double)items_count;
}


// Search type functions
bool Hashing::is_same_key(Node node, int key) {
    return !node.is_empty && node.key != key;
}

bool Hashing::not_empty_node(Node node, int key) {
    return !node.is_empty;
}

// Advanced
void Hashing::delete_item(int position) {
    set_item(Node::empty_node(), position);
}

int Hashing::item_position(int key) {
    return get<0>(search(key, this->is_same_key ));
}

int Hashing::time_spent(int key) {
    return get<2>(search(key, this->is_same_key ));
}
// Receives key to be used to find positions, and criteria
// that will identify proper position, if exists
// Returns position, node at position and amount of iterations to find
tuple<int, Node, int> Hashing::search(
        int key,
        bool(* criteria)(Node, int),
        int(Hashing::* position_calculator)(int, int, Node)) {

    int position = (this->*position_calculator)(-1, key, Node::empty_node());
    Node node = get_item(position);
    int counter = 1;
    while(criteria(node, key)) {
        position = (this->*position_calculator)(position, key, node);
        // Has searched entire file
        if(counter > this->size || position == -1) {
            return make_tuple(-1, Node::empty_node(), counter);
        }
        node = get_item(position);
        counter++;
    }
    return make_tuple(position, node, counter);
}

// Config
void Hashing::setup() {
    // Check if file exists
    if(!ifstream(filepath)) {
        fstream file(filepath, ios::binary | ios::app);
        if(file.is_open()) {
            for(int i = 0; i < this->size; i++) {
                Node node = Node::empty_node();
                file.write((char*) &node, sizeof(Node));
            }
            file.close();
        }
    }
}

// File manipulation
Node Hashing::get_item(int position) {
    ifstream file(filepath, ios::binary);
    Node* searched = (Node*) malloc(sizeof(Node));
    if(file.is_open()) {
        file.seekg(sizeof(Node) * position, ios_base::beg);
        file.read((char*)searched, sizeof(Node));
        file.close();
    }
    return *searched;
}

void Hashing::set_item(Node node, int position) {
    fstream file(filepath, ios::binary|ios::in|ios::out);
    if(file.is_open()) {
        file.seekp(sizeof(Node) * position, ios_base::beg);
        file.write((char*) &node, sizeof(Node));
        file.close();
    }
}