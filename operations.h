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

struct node* createNode(struct node* head, int ID, char name[], char programme[], float mark); 

void openDatabase(); // function to open database file and read in all records
void showAll(struct node* head); // function to show all the current records
void insertRecord(struct node* head); // function to add a new record to the database
void queryStudent(struct node* head); // function to query a specific student by ID
void updateStudent(struct node* head); // function to update the value for a given record
void deleteStudent(struct node* head); // function to delete a record from the database
void saveRecords(struct node* head); // function to save all the records to the database file
void mergeSort(struct node* head); // function for sorting student records
void summaryStats(struct node* head); // function for summary of database

#endif