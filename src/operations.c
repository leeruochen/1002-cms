#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"


Node* createNode(int id, StudentData* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
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
        float mark = atof(token); // ascii to float

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

void showAll(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("ID: %d Name: %-15s Programme: %-22s Mark: %.1f\n", 
            root->id, root->data->name, root->data->programme, root->data->mark);
    showAll(root->left);
    showAll(root->right);
}

Node* insertRecord(Node* root, int id, StudentData* data) {
    if (root == NULL) {
        return createNode(id, data); // Create new node if tree is empty or at leaf position
    }
    if (id < root->id) { // if id is less than current node's id, go left
        root->left = insertRecord(root->left, id, data); // Recursive call to left subtree
    } else if (id > root->id) { // if id is greater than current node's id, go right
        root->right = insertRecord(root->right, id, data); // Recursive call to right subtree
    } else { // if id already exists, do not insert duplicate
        printf("Student Record for %d already exists! Skipping record.", id);
    }
    return root; // return the root of tree
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
Node* findStudent(Node* root, int id) {
    if (root == NULL || root->id == id)
        return root;  // Found the node or tree is empty

    // Recurse through the left or right subtrees
    if (id < root->id)
        return findStudent(root->left, id);
    else
        return findStudent(root->right, id);
}

