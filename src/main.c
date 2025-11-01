#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "operations.h"


int main(void)
{
    char choice[StringLimit];
    int choice_int;
    printf("Welcome to the Class Management System.\n\n");
    Node* root = openDatabase("../db/P11_3-CMS.txt"); // Start with empty tree
    
    do {
        printf("\nPlease choose from the following list of instructions.\n\n");
        printf("1. Show all records.\n");
        printf("2. Insert a new record.\n");
        printf("3. Query a student record by ID.\n");
        printf("4. Update an existing record.\n");
        printf("5. Delete an existing record.\n");
        printf("6. Save all records into the database.\n");
        printf("7. Sort the student records.\n");
        printf("8. View the summary of the records.\n");
        printf("9. Exit the program.\n\n");
        printf("Enter your choice (1-9): ");
        fgets(choice, StringLimit, stdin);
        choice[strcspn(choice, "\n")] = '\0';
        choice_int = atoi(choice);

        if (choice_int == 0){
            printf("Invalid choice. Please try again.\n\n");
            continue;
        }
        if (choice_int < 1 || choice_int > 9) {
            printf("Invalid choice. Please try again.\n\n");
        }

        switch (choice_int) {
            case 1:
                showAll(root);
                break;
            case 2:
                int new_id = getStudentIdInput();
                if (checkDuplicateID(root, new_id)) {
                    printf("Student Record for ID:%d already exists! Cannot insert duplicate ID.\n", new_id);
                    break;
                }
                StudentData* newData = createStudentData();
                root = insertRecord(root, new_id, newData);
                break;
            case 3:
                queryStudent(root);
                break;
            case 4:
                updateStudent(root);
                break;
            case 5:
                int id = getStudentIdInput();

                if (findStudent(root, id) == NULL) {
                    printf("Error: Student ID %d not found.\n", id);
                } else {
                        char confirm[StringLimit];
                        printf("Are you sure you want to delete student with ID %d? (y/n): ", id);
                        fgets(confirm, StringLimit, stdin);
                        confirm[strcspn(confirm, "\n")] = '\0';
                    if (tolower(confirm[0]) == 'y') {
                        // root = deleteStudent(root, id); not done yet, just uncomment it when you finish the deleteStudent function
                        printf("Student deleted successfully.\n");
                    } else {
                        printf("Deletion cancelled.\n");
                    }
                }
                break;
            case 6:
                saveRecords(root);
                break;
            case 7:
                mergeSort(root);
                break;
            case 8:
                summaryStats(root);
                break;
        }
        if (choice_int != 9 && choice_int >= 1 && choice_int <= 8) {
            hold();
        }
    } while (choice_int != 9);

    freeTree(root);
    printf("Thank you for using the Class Management System.\n");

    return 0;
}