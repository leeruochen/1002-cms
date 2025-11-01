#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

Node* createNode(struct node* head, int ID, char name[], char programme[], float mark)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ID = ID;
    strcpy(newNode->name, name);
    strcpy(newNode->programme, programme);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void openDatabase() {
    //write your algorithms here
}

void showAll(struct node* head) {
    //write your algorithms here
}

void insertRecord(struct node* head) {
    //write your algorithms here
}

void queryStudent(struct node* head) {
    //write your algorithms here
}

void updateStudent(struct node* head) {
    //write your algorithms here
}

void deleteStudent(struct node* head) {
    //write your algorithms here
}

void saveRecords(struct node* head) {
    //write your algorithms here
}

void mergeSort(struct node* head) {
    //write your algorithms here
}

void summaryStats(struct node* head) {
    //write your algorithms here
}

