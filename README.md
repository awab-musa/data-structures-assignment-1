# Student Records Management System

**Data Structures: Programming Assignment 1**
Cairo University, Faculty of Computing and Artificial Intelligence

**Author:** `<your name>` | **Student ID:** `<your ID>`

A C++ program that manages student records using a **singly linked list**, with two manually implemented sorting algorithms (**Insertion Sort** and **Quick Sort**) and **linear search** by Student ID.

---

## Student Record

| Field      | Type     | Description                |
|------------|----------|----------------------------|
| Student ID | `int`    | Unique positive integer    |
| Name       | `string` | Student name               |
| Grade      | `int`    | Integer from 0 to 100      |

---

## Features

- **Singly linked list** with a `head` pointer; nodes are dynamically allocated and the last node points to `nullptr`.
- **Insert at end** and **display all records** in list order.
- **Destructor** that frees every node before the program exits.
- **Insertion Sort**: sorts by grade in descending order by re-linking nodes.
- **Quick Sort**: sorts by grade in descending order, with manual partitioning and recursion (swaps whole records).
- **Linear Search**: finds a student by exact ID and works before and after sorting.
- Input validation when inserting: positive ID, grade between 0 and 100, and no duplicate IDs.

---

## Why Linear Search?

A singly linked list can only be traversed forward, one node at a time. It has no random access like an array, so binary search is not possible. Linear search works directly on the nodes and on both sorted and unsorted lists.

---

## Assignment Rules Followed

- Written in C++ with a singly linked list and a head pointer.
- Both Insertion Sort and Quick Sort are implemented manually.
- All insertion, display, sorting, and searching are methods of the `SinglyLinkedList` class.
- No arrays, vectors, or STL linked lists are used to store records.
- No built-in sorting or searching algorithms are used.
- Whole records are swapped (ID, name, and grade together), never partial fields.
- Both sorts run on the same original records.

---

## How to Compile and Run

Requires a C++ compiler such as `g++`.

```bash
g++ -Wall -o student_records student_records.cpp
./student_records
```

On Windows (PowerShell or CMD):

```bash
g++ -Wall -o student_records.exe student_records.cpp
student_records.exe
```

---

## Sample Output

```
Original List
ID	Name	Grade
101	Ahmed	75
102	Sara	92
103	Omar	68
104	Mona	85
105	Ali	80

After Insertion Sort
ID	Name	Grade
102	Sara	92
104	Mona	85
105	Ali	80
101	Ahmed	75
103	Omar	68

After Quick Sort
ID	Name	Grade
102	Sara	92
104	Mona	85
105	Ali	80
101	Ahmed	75
103	Omar	68

Searching
Enter Student ID: 104

Search Result:
Student Found!
ID: 104, Name: Mona, Grade: 85
```

If the entered ID does not exist, the program prints:

```
Student not found.
```

---

## Project Structure

```
.
├── student_records.cpp   # complete implementation (single-file submission)
└── README.md
```
