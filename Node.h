#ifndef NODE_H
#define NODE_H

#include <string>

// Node: one student record in the linked list
struct Node {
    int id;
    std::string name;
    int grade;
    Node* next;
};

#endif