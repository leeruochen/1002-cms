#ifndef OPERATIONS_H
#define OPERATIONS_H
#define StringLimit 50

typedef struct Node { // node structure for linked list to store student information
    int ID;
    char name[StringLimit];
    char programme[StringLimit];
    float mark;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(Node* head, int ID, char name[], char programme[], float mark); 

void openDatabase(root); // function to open database file and read in all records
void showAll(Node* head); // function to show all the current records
void insertRecord(Node* head); // function to add a new record to the database
void queryStudent(Node* head); // function to query a specific student by ID
void updateStudent(Node* head); // function to update the value for a given record
void deleteStudent(Node* head); // function to delete a record from the database
void saveRecords(Node* head); // function to save all the records to the database file
void mergeSort(Node* head); // function for sorting student records
void summaryStats(Node* head); // function for summary of database

#endif