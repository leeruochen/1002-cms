#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

Node* createNode(Node* head, int ID, char name[], char programme[], float mark)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ID = ID;
    strcpy(newNode->name, name);
    strcpy(newNode->programme, programme);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void openDatabase(root) {
    FILE *fptr;

    fptr = fopen("../db/P11_3-CMS.txt", "r");

}

void showAll(Node* head) {
    //write your algorithms here
}

void insertRecord(Node* head) {
    //write your algorithms here
}

void queryStudent(Node* head) {
    //write your algorithms here
}

void updateStudent(Node* head) {
    //write your algorithms here
}

void deleteStudent(Node* head) {
    //write your algorithms here
}

void saveRecords(Node* head) {
    //write your algorithms here
}

void mergeSort(Node* head) {
    //write your algorithms here
}

void summaryStats(Node* head) {
    //write your algorithms here
}

