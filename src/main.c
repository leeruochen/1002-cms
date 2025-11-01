#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"


int main(void)
{
    int choice;
    int scanf_check;
    printf("Welcome to the Class Management System.\n\n");
    Node* root = openDatabase("../db/P11_3-CMS.txt"); // Start with empty tree
    
    do {
        printf("Please choose from the following list of instructions.\n\n");
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
        scanf_check = scanf("%d", &choice);

        if (scanf_check == 0){
            printf("Invalid choice. Please try again.\n\n");
            while (getchar() != '\n');
            continue;
        }
        if (choice < 1 || choice > 9) {
            printf("Invalid choice. Please try again.\n\n");
        }

        switch (choice) {
            case 1:
                showAll(root);
                break;
            case 2:
                int id;
                char name[StringLimit];
                char programme[StringLimit];
                float mark;
                
                printf("Please enter the Student's ID:\n");
                scanf("%d", &id);
                printf("Please enter the Student's Name:\n");
                fgets(name, StringLimit, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Please enter the Student's Programme:\n");
                fgets(programme, StringLimit, stdin);
                programme[strcspn(programme, "\n")] = '\0';
                printf("Please enter the Student's Mark:\n");
                scanf("%f", &mark);

                StudentData* newData = (StudentData*)malloc(sizeof(StudentData));
                newData->name = strdup(name);
                newData->programme = strdup(programme);
                newData->mark = mark;

                root = insertRecord(root, id, newData);
                break;
            case 3:
                queryStudent(root);
                break;
            case 4:
                updateStudent(root);
                break;
            case 5:
                deleteStudent(root);
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
    } while (choice != 9);

    printf("Thank you for using the Class Management System.\n");

    return 0;
}