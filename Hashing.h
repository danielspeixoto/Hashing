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
    explicit Hashing(int size,
                     string filepath);

    virtual void insert(Node node);
    virtual bool remove(int key) {};
    virtual void read() {};
    Node search(int key);
    double time_spent();
    int time_spent(int key);

protected:
    int size;
    virtual int search_calculator(int current,
                                  int key,
                                  Node node) = 0;
    virtual int insert_calculator(int current,
                                  int key,
                                  Node node) = 0;
    Node get_item(int position);
    void set_item(Node node, int position);
    void delete_item(int position);
    int item_position(int key);

private:
    static bool is_same_key(Node node, int key);
    static bool not_empty_node(Node node, int key);
    void setup();
    string filepath;

    tuple<int, Node, int> search(
            int key,
            bool (*criteria)(Node, int),
            int (Hashing::*position_calculator)(int, int, Node) = &Hashing::search_calculator);
};


#endif //HASHING_HASHING_H



