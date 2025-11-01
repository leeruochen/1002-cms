#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"


int main(void)
{
    int choice;
    int scanf_check;
    Node* root = NULL; // Start with empty list
    printf("Welcome to the Class Management System.\n\n");
    
    do {
        printf("Please choose from the following list of instructions.\n\n");
        printf("1. Open the database.\n");
        printf("2. Show all records.\n");
        printf("3. Insert a new record.\n");
        printf("4. Query a student record by ID.\n");
        printf("5. Update an existing record.\n");
        printf("6. Delete an existing record.\n");
        printf("7. Save all records into the database.\n");
        printf("8. Sort the student records.\n");
        printf("9. View the summary of the records.\n");
        printf("10. Exit the program.\n\n");
        printf("Enter your choice (1-10): ");
        scanf_check = scanf("%d", &choice);

        if (scanf_check == 0){
            printf("Invalid choice. Please try again.\n\n");
            while (getchar() != '\n');
            continue;
        }
        if (choice < 1 || choice > 10) {
            printf("Invalid choice. Please try again.\n\n");
        }

        switch (choice) {
            case 1:
                openDatabase();
            case 2:
                showAll(root);
            case 3:
                insertRecord(root);
            case 4:
                queryStudent(root);
            case 5:
                updateStudent(root);
            case 6:
                deleteStudent(root);
            case 7:
                saveRecords(root);
            case 8:
                mergeSort(root);
            case 9:
                summaryStats(root);
        }
    } while (choice != 10);

    printf("Thank you for using the Class Management System.\n");

    return 0;
}