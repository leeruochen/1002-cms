#ifndef OPERATIONS_H
#define OPERATIONS_H

#define StringLimit 50

typedef struct StudentData { // data struct
    char* name;
    char* programme;
    float mark;
} StudentData;

typedef struct Node { // binary tree node
    int ID;
    StudentData* data; 
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int ID, StudentData* data); 

Node* openDatabase(const char* filename); // function to open database file and read in all records
void showAll(Node* head); // function to show all the current records
Node* insertRecord(Node* root, int id, StudentData* data); // function to add a new record to the database
void queryStudent(Node* head); // function to query a specific student by ID
void updateStudent(Node* head); // function to update the value for a given record
void deleteStudent(Node* head); // function to delete a record from the database
void saveRecords(Node* head); // function to save all the records to the database file
void mergeSort(Node* head); // function for sorting student records
void summaryStats(Node* head); // function for summary of database

#endif