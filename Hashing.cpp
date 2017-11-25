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

using namespace std;

Hashing::Hashing(int size, string filepath) {
    this->size = size;
    this->filepath = filepath;
    setup();
}

bool is_same_key2(Node node, int key) {
    return !node.is_empty && node.key != key;
}

// Main Functions
Node Hashing::search(int key) {
    return get<1>(search(key, this->is_same_key ));
}

void Hashing::insert(Node node) {
    //TODO Use do_upon_node_existence
    int position = get<0>(search(node.key, this->not_empty_node));
    if(position != -1) {
        set_item(node, position);
    }
}

bool Hashing::remove(int key) {
    do_upon_node_existence(key,
                           this->delete_item,
                           this->item_not_found);
}

// Answer type functions
bool Hashing::is_same_key(Node node, int key) {
    return !node.is_empty && node.key != key;
}

bool Hashing::not_empty_node(Node node, int key) {
    return !node.is_empty;
}

void Hashing::item_not_found(int position, int key) {
    cout << "chave não encontrada " << key << endl;
}

//TODO Fix this
void Hashing::delete_item(int position, int key, Node node) {
//    set_item(Node::empty_node(), position);
}

// Advanced
tuple<int, Node> Hashing::item_and_position_from_key(int key) {
    return search(key, this->is_same_key);
}

// Receives key to be used to find positions, and criteria
// that will identify proper position, if exists
tuple<int, Node> Hashing::search(
        int key,
        bool(* criteria)(Node, int) ) {

    int position = position_calculator(-1, key);
    int counter = 0;
    Node node = get_item(position);
    while(criteria(node, key)) {
        position = position_calculator(position, key);
        counter++;
        // Has searched entire file
        if(counter > this->size) {
            return make_tuple(-1, Node::empty_node());
        }
        node = get_item(position);
    }
    return make_tuple(position, node);
}

void Hashing::do_upon_node_existence(
        int key,
        void(* success_operation)(int, int, Node),
        void(* failure_operation)(int, int)) {

    int position = position_from_key(key);
    if(position != -1) {
        success_operation(position, key, get_item(position));
    }
    failure_operation(position, key);
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
