#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <string>
#include "Node.h"

// SinglyLinkedList: stores students and does sorting/searching
class SinglyLinkedList {
private:
    Node* head;

    // ----- private helper methods -----
    void swapRecords(Node* a, Node* b);               // swap whole record of two nodes
    Node* getTail() const;                            // last node of the list
    Node* partition(Node* low, Node* high);           // quick sort partition step
    void quickSortHelper(Node* low, Node* high);      // recursive quick sort

public:
    SinglyLinkedList();                               // constructor
    ~SinglyLinkedList();                              // destructor (frees nodes)

    void insertStudent(int id, std::string name, int grade);  // insert at the end
    void displayStudents() const;                     // print all records
    void insertionSort();                             // sort by grade (descending)
    void quickSort();                                 // sort by grade (descending)
    Node* searchStudent(int id) const;                // linear search by ID
};

#endif