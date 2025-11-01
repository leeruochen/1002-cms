#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"


Node* createNode(int ID, StudentData* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ID = ID;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* openDatabase(const char* filename) {
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }
    
    char buffer[1024]; 
    for (int i = 0; i < 5; i++) { // skip first few lines
        if (fgets(buffer, sizeof(buffer), fptr) == NULL) {
            break;
        }
    }

    Node* root = NULL;
    const char* delimiter = "\t"; // sample file used tab as delimiter

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        char* token;

        token = strtok(buffer, delimiter); //strtok separates the words in the file with delimiter
        if (token == NULL) continue;
        int id = atoi(token); //atoi converts string/ascii to integer

        token = strtok(NULL, delimiter);
        if (token == NULL) continue;
        char* name = strdup(token); //strdup duplicates the string from buffer

        token = strtok(NULL, delimiter);
        if (token == NULL) continue;
        char* programme = strdup(token);

        token = strtok(NULL, delimiter);
        if (token == NULL) continue;
        float mark = atof(token);

        StudentData* newData = (StudentData*)malloc(sizeof(StudentData));
        newData->name = name;
        newData->programme = programme;
        newData->mark = mark;

        root = insertRecord(root, id, newData);
    }
    fclose(fptr);
    printf("Data loaded successfully.\n");
    return root;

}

void showAll(Node* head) {
    //write your algorithms here
}

Node* insertRecord(Node* root, int id, StudentData* data) {
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

