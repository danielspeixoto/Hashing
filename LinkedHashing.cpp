//
// Created by daniel on 11/22/17.
//

#include <tuple>
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

//TODO Test
bool LinkedHashing::remove(int key) {
    int nodeClass = key % size;
    tuple<int, Node, int> search = search_data(key);
    int position = get<0>(search);
    if(position < 0) {
        return false;
    }
    Node node = get<1>(search);
    // First element
    if(nodeClass == position) {
        if(node.next != -1) {
            // Moves the next node
            Node realocted = get_item(node.next);
            set_item(realocted, nodeClass);
            delete_item(node.next);
        }
    } else {
        tuple<int, Node, int> search_previous = search_data(key,
                                                            &Hashing::previous_node);
        int previous_position = get<0>(search_previous);
        Node previous = get<1>(search_previous);
        previous.next = node.next;
        set_item(previous, previous_position);
        delete_item(position);
    }
    return true;
}

int LinkedHashing::getLastEmptyPosition(int lastPosition) {
    while(!get_item(lastPosition).is_empty) {
        lastPosition--;
        if(lastPosition < 0) {
            // Not valid insertion
            return -1;
        }
    }
    return lastPosition;
}

//TODO
int LinkedHashing::insert_calculator(int current, int key, Node node) {
    if(current == -1) {
        return key % size;
    }
    if(node.next != -1) {
        if(node.key % size != key % size) {
            //TODO
            remove(current);
            int position = getLastEmptyPosition(size - 1);
            if(position == current) {
                position = getLastEmptyPosition(current - 1);
            }
            set_item(node, position);
            return current;
        }
        return node.next;
    }

    node.next = getLastEmptyPosition(size - 1);
    set_item(node, current);
    return node.next;
}

int LinkedHashing::search_calculator(int current, int key, Node node) {
    if(current == -1) {
        return key % size;
    }
    return node.next;
}
