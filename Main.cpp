#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

// Fill a list with the same 5 predefined students
void fillStudents(SinglyLinkedList& list) {
    list.insertStudent(101, "Ahmed", 75);
    list.insertStudent(102, "Sara", 92);
    list.insertStudent(103, "Omar", 68);
    list.insertStudent(104, "Mona", 85);
    list.insertStudent(105, "Ali", 80);
}

// Print the result of a search
void printSearchResult(Node* result) {
    cout << "Search Result:" << endl;
    if (result != nullptr) {
        cout << "Student Found!" << endl;
        cout << "ID: " << result->id << ", Name: " << result->name
             << ", Grade: " << result->grade << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

int main() {
    // Two lists with the same original data, so both sorts start
    // from the same original records
    SinglyLinkedList insertionList;
    SinglyLinkedList quickList;
    fillStudents(insertionList);
    fillStudents(quickList);

    cout << "Original List" << endl;
    insertionList.displayStudents();

    cout << "\nAfter Insertion Sort" << endl;
    insertionList.insertionSort();
    insertionList.displayStudents();

    cout << "\nAfter Quick Sort" << endl;
    quickList.quickSort();
    quickList.displayStudents();

    // Searching
    int searchId;
    cout << "\nSearching" << endl;
    cout << "Enter Student ID: ";
    cin >> searchId;

    if (cin.fail()) {
        cout << "Invalid input." << endl;
        return 0;
    }

    // Search works after sorting
    cout << endl;
    printSearchResult(quickList.searchStudent(searchId));

    // Search also works before sorting (on a fresh unsorted list)
    SinglyLinkedList freshList;
    fillStudents(freshList);
    cout << "\n(Search on the unsorted list)" << endl;
    printSearchResult(freshList.searchStudent(searchId));

    return 0;
}


/*
For Running :- 

g++ Main.cpp SinglyLinkedList.cpp -o student_system
./student_system

*/