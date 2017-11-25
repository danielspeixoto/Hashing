//
// Created by daniel on 11/23/17.
//

#include "Node.h"

Node::Node(int key, char* name, int age) {
    this->key = key;
    this->name = name;
    this->age = age;
}

string Node::hashingFormat() {
    return "";
//    return to_string(this->key) + ": " +
//            this->name + " " +
//            to_string(this->age);
}
