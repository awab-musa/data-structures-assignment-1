#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

// =========================================================
// Constructor / Destructor
// =========================================================

// Constructor: start with an empty list
SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
}

// Destructor: free every node
SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

// =========================================================
// Insert and Display
// =========================================================

// Insert a new student at the END of the list
void SinglyLinkedList::insertStudent(int id, string name, int grade) {
    // Simple validation
    if (id <= 0) {
        cout << "Invalid ID (must be positive): " << id << endl;
        return;
    }
    if (grade < 0 || grade > 100) {
        cout << "Invalid grade (must be 0-100): " << grade << endl;
        return;
    }
    // IDs must be unique
    Node* check = head;
    while (check != nullptr) {
        if (check->id == id) {
            cout << "ID " << id << " already exists." << endl;
            return;
        }
        check = check->next;
    }

    Node* newNode = new Node;
    newNode->id = id;
    newNode->name = name;
    newNode->grade = grade;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;             // first node
    } else {
        getTail()->next = newNode;  // attach after the last node
    }
}

// Print all students in list order
void SinglyLinkedList::displayStudents() const {
    cout << "ID\tName\tGrade" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << current->id << "\t" << current->name << "\t"
             << current->grade << endl;
        current = current->next;
    }
}

// =========================================================
// Insertion Sort
// =========================================================

// Insertion Sort (descending by grade) by re-linking nodes
void SinglyLinkedList::insertionSort() {
    Node* sorted = nullptr;   // the new sorted list
    Node* current = head;     // node we are about to insert

    while (current != nullptr) {
        Node* nextNode = current->next;  // remember the next one

        if (sorted == nullptr || current->grade > sorted->grade) {
            // goes at the front of the sorted list
            current->next = sorted;
            sorted = current;
        } else {
            // find the right place inside the sorted list
            Node* temp = sorted;
            while (temp->next != nullptr &&
                   temp->next->grade >= current->grade) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }
    head = sorted;
}

// =========================================================
// Quick Sort
// =========================================================

// Swap the WHOLE record (id, name, grade) of two nodes
void SinglyLinkedList::swapRecords(Node* a, Node* b) {
    int tempId = a->id;
    string tempName = a->name;
    int tempGrade = a->grade;

    a->id = b->id;
    a->name = b->name;
    a->grade = b->grade;

    b->id = tempId;
    b->name = tempName;
    b->grade = tempGrade;
}

// Return the last node of the list (nullptr if the list is empty)
Node* SinglyLinkedList::getTail() const {
    Node* current = head;
    if (current == nullptr) return nullptr;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

// Partition the part of the list from low to high (inclusive).
// The pivot is the last node (high). Bigger grades go to the left
// so the final order is descending. Returns the pivot's final node.
Node* SinglyLinkedList::partition(Node* low, Node* high) {
    int pivotGrade = high->grade;
    Node* i = low;  // i marks where the next bigger grade should go

    for (Node* j = low; j != high; j = j->next) {
        if (j->grade > pivotGrade) {
            swapRecords(i, j);
            i = i->next;
        }
    }
    // put the pivot in its correct place
    swapRecords(i, high);
    return i;
}

// Recursive quick sort on the nodes from low to high (inclusive)
void SinglyLinkedList::quickSortHelper(Node* low, Node* high) {
    if (low == nullptr || high == nullptr || low == high) {
        return;  // 0 or 1 node: already sorted
    }

    Node* pivot = partition(low, high);

    // Sort the left part (nodes before the pivot)
    if (pivot != low) {
        Node* beforePivot = low;
        while (beforePivot->next != pivot) {
            beforePivot = beforePivot->next;
        }
        quickSortHelper(low, beforePivot);
    }

    // Sort the right part (nodes after the pivot)
    if (pivot != high) {
        quickSortHelper(pivot->next, high);
    }
}

// Quick Sort (descending by grade)
void SinglyLinkedList::quickSort() {
    Node* tail = getTail();
    quickSortHelper(head, tail);
}

// =========================================================
// Searching
// =========================================================

// Linear search by ID.
// Linear search is appropriate for a singly linked list because we can
// only move forward node by node (no random access like an array, so
// binary search is not possible), and it works on sorted or unsorted data.
Node* SinglyLinkedList::searchStudent(int id) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            return current;  // found
        }
        current = current->next;
    }
    return nullptr;  // not found
}