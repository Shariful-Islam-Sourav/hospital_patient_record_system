#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

int main() {
    loadFromFile();   // Load old data
    initMemory();     // Prepare memory for adding new patients

    int choice;

    while (1) {
        printf("\n--- Hospital Patient Record System ---\n");
        printf("1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                saveToFile();
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid option. Try again.\n");
        }
    }

    return 0;
}
