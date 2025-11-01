#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    showAll(root->left);
    printf("ID: %-10d Name: %-15s Programme: %-22s Mark: %.1f\n", 
            root->id, root->data->name, root->data->programme, root->data->mark);
    
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

StudentData* createStudentData(int* id) {
    char temp_id[StringLimit];
    char name[StringLimit];
    char programme[StringLimit];
    char temp_mark[StringLimit];
    do {
        printf("Please enter the Student's ID:\n");
        fgets(temp_id, StringLimit, stdin);
        temp_id[strcspn(temp_id, "\n")] = '\0';
        if (!checkValidInteger(temp_id)) {
            printf("The ID entered is invalid. Please try again.\n");
        } else {
            *id = atoi(temp_id);
        }
    } while (!checkValidInteger(temp_id));

    do {
        printf("Please enter the Student's Name:\n");
        fgets(name, StringLimit, stdin);
        name[strcspn(name, "\n")] = '\0';
        if (!checkValidString(name)) {
            printf("The name entered is invalid. Please try again.\n");
        }
    } while (!checkValidString(name));

    do {
        printf("Please enter the Student's Programme:\n");
        fgets(programme, StringLimit, stdin);
        programme[strcspn(programme, "\n")] = '\0';
        if (!checkValidString(programme)) {
            printf("The programme entered is invalid. Please try again.\n");
        }
    } while (!checkValidString(programme));

    int clear = 1;
    do {
        printf("Please enter the Student's Mark:\n");
        fgets(temp_mark, StringLimit, stdin);
        temp_mark[strcspn(temp_mark, "\n")] = '\0';

        char* pend;
        float temp_val = strtof(temp_mark, &pend);
        if (pend == temp_mark || *pend != '\0') {
            printf("The mark entered is invalid. Please try again.\n");
        } else if (temp_val < 0.0 || temp_val > 100.0) {
            printf("The mark entered is out of range. Please try again.\n");
        } else {
            clear = 0;
        }
    } while (clear == 1);

    StudentData* newData = (StudentData*)malloc(sizeof(StudentData));
    newData->name = strdup(name);
    newData->programme = strdup(programme);
    newData->mark = atof(temp_mark);
    return newData;
}

int checkValidString(const char* str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && !isspace(str[i])) {
            return 0;
        }
    }
    return 1;
}

int checkValidInteger(const char* int_str) {
    if (int_str == NULL || strlen(int_str) == 0) {
        return 0;
    }

    for (int i = 0; int_str[i] != '\0'; i++) {
        if (!isdigit(int_str[i])) {
            return 0;
        }
    }
    return 1;
}

void queryStudent(Node* root) {
    //write your algorithms here
}

void updateStudent(Node* root) {
    //write your algorithms here
}

void deleteStudent(Node* root) {
    //write your algorithms here
}

void saveRecords(Node* root) {
    //write your algorithms here
}

void mergeSort(Node* root) {
    //write your algorithms here
}

void summaryStats(Node* root) {
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

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root->data->name);
    free(root->data->programme);
    free(root->data);
    free(root);
}