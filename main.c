#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

int main() {

    // Load data from file (if exists)
    loadFromFile();
    int choice;

    while (1) {
        printf("\n=======================================\n");
        printf("           MediRecord System           \n");
        printf("=======================================\n");

        // Main menu options
        printf("1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Save & Exit\n");
        printf("4. Search Patient\n");
        printf("5. Update Patient\n");
        printf("6. Delete Patient\n");
        printf("7. Sort by Name (A-Z)\n");
        printf("8. Sort by ID\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Perform requested operation
        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;

            case 3:
                saveToFile();
                free(patients); // Free allocated memory before exit
                return 0;

            case 4: searchPatient(); break;
            case 5: updatePatient(); break;
            case 6: deletePatient(); break;
            case 7: sortByName(); break;
            case 8: sortByID(); break;

            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
