#include "operations.h"

struct node* insertAtHead(struct node* head, int ID, char name[], char programme[], float mark)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->ID = ID;
    strcpy(newNode->name, name);
    strcpy(newNode->programme, programme);
    newNode->mark = mark;
    newNode->next = head;
    return newNode;
}


void openDatabase() {}

void showAll(struct node* head) {}

void insertRecord(struct node* head) {}

void queryStudent(struct node* head) {}

void updateStudent(struct node* head) {}

void deleteStudent(struct node* head) {}

void saveRecords(struct node* head) {}

void mergeSort(struct node* head) {}

void summaryStats(struct node* head) {}

