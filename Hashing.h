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

    void insert(Node node);
    bool remove(int key);
    Node search(int key);
    virtual void read() {};

protected:
    int size;
    virtual int position_calculator(int current, int key) = 0;
    Node get_item(int position);
    void set_item(Node node, int position);
    virtual int position_from_key(int key) {};
    static void item_not_found(int position, int key);
    static void delete_item(int position, int key, Node node);
    static bool is_same_key(Node node, int key);
    static bool not_empty_node(Node node, int key);
    void do_upon_node_existence(int key,
                                void (* success_operation)
                                        (int, int, Node),
                                void (* failure_operation)
                                        (int, int));

private:
    void setup();
    string filepath;

    tuple<int, Node> item_and_position_from_key(int key);
    tuple<int, Node> search(int key, bool (*criteria)(Node, int));
};


#endif //HASHING_HASHING_H



