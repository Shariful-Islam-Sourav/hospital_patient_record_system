#include <stdio.h>
#include "patient.h"

int main() {
    loadFromFile();

    int choice;

    while (1) {
        printf("\n--- MediRecord System ---\n");
        printf("1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Save & Exit\n");
        printf("4. Search Patient\n");
        printf("5. Update Patient\n");
        printf("6. Delete Patient\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: saveToFile(); return 0;
            case 4: searchPatient(); break;
            case 5: updatePatient(); break;
            case 6: deletePatient(); break;
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
