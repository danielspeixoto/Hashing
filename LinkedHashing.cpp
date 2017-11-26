//
// Created by daniel on 11/22/17.
//

#include "LinkedHashing.h"

using namespace std;

void LinkedHashing::read() {
    for(int i = 0; i < this->size; i++) {
        cout << i << ": ";
        Node node = this->get_item(i);
        if(node.is_empty) {
            cout << Node::empty << endl;
        } else {
            cout << node.hashingFormat() << " ";
            if(node.next == -1) {
                cout << "nulo";
            } else {
                cout << node.next;
            }
            cout  << endl;
        }
    }
}

//TODO
bool LinkedHashing::remove(int key) {
    int position = item_position(key);
    if(position == -1) return false;
    delete_item(position);
    return true;
}

int LinkedHashing::insert_calculator(int current, int key, Node node) {
    if(current == -1) {
        return key % size;
    }
    if(node.next != -1) {
        return node.next;
    }
    int i = 1;
    while(!get_item((current + i) % size).is_empty) {
        i++;
    }
    node.next = (current + i) % size;
    set_item(node, current);
    return node.next;
}

int LinkedHashing::search_calculator(int current, int key, Node node) {
    if(current == -1) {
        return key % size;
    }
    return node.next;
}
