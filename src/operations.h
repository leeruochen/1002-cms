#ifndef OPERATIONS_H
#define OPERATIONS_H

#define StringLimit 50

typedef struct StudentData { // data struct
    char* name;
    char* programme;
    float mark;
} StudentData;

typedef struct Node { // binary tree node
    int id;
    StudentData* data; 
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int ID, StudentData* data); 

Node* openDatabase(const char* filename); // function to open database file and read in all records
void showAll(Node* root); // function to show all the current records
Node* insertRecord(Node* root, int id, StudentData* data); // function to add a new record to the database
StudentData* createStudentData(int* id); // function to create a new student data record
int checkValidString(const char* str); // function to check if a string is valid
int checkValidInteger(const char* str); // function to check if an integer is valid
void queryStudent(Node* root); // function to query a specific student by ID
void updateStudent(Node* root); // function to update the value for a given record
void deleteStudent(Node* root); // function to delete a record from the database
void saveRecords(Node* root); // function to save all the records to the database file
void mergeSort(Node* root); // function for sorting student records
void summaryStats(Node* root); // function for summary of database
void freeTree(Node* root); // function to free all allocated memory for the binary tree

#endif