#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

// Dynamic array pointer and counters
struct Patient *patients = NULL;
int patientCount = 0;
int capacity = 0;

// Expands array size when needed
void ensureCapacity() {
    if (patientCount == capacity) {
        capacity = (capacity == 0) ? 2 : capacity * 2;
        patients = realloc(patients, capacity * sizeof(struct Patient));

        // If memory allocation fails, exit the program
        if (!patients) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
}

// Simple check for correct date format (YYYY-MM-DD)
int isValidDate(char *d) {
    if (strlen(d) != 10) return 0;
    if (d[4] != '-' || d[7] != '-') return 0;
    return 1;
}

void addPatient() {
    ensureCapacity();
    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    // Prevent duplicate ID entries
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == p.id) {
            printf("\nError: Patient ID already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    // Simple age check
    if (p.age <= 0 || p.age > 120) {
        printf("\nInvalid age!\n");
        return;
    }

    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);

    printf("Enter Doctor: ");
    scanf(" %[^\n]", p.doctor);

    printf("Enter Admission Date (YYYY-MM-DD): ");
    scanf(" %[^\n]", p.admissionDate);

    // Validate date format
    if (!isValidDate(p.admissionDate)) {
        printf("\nInvalid date format!\n");
        return;
    }

    // Add to array
    patients[patientCount++] = p;

    printf("\nPatient added successfully!\n");
}

void displayPatients() {
    if (patientCount == 0) {
        printf("\nNo patient records available.\n");
        return;
    }

    printf("\n=========== Patient List ===========\n");

    // Loop through the whole array to show all records
    for (int i = 0; i < patientCount; i++) {
        printf("\nPatient %d:\n", i + 1);
        printf("ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Disease: %s\n", patients[i].disease);
        printf("Doctor: %s\n", patients[i].doctor);
        printf("Admission Date: %s\n", patients[i].admissionDate);
    }
}

void searchPatient() {
    int id;
    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    // Linear search by ID
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("\n--- Patient Found ---\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Disease: %s\n", patients[i].disease);
            printf("Doctor: %s\n", patients[i].doctor);
            printf("Admission Date: %s\n", patients[i].admissionDate);
            return;
        }
    }

    printf("\nPatient not found.\n");
}

void updatePatient() {
    int id;
    printf("\nEnter Patient ID to update: ");
    scanf("%d", &id);

    // Search patient to update
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {

            printf("\n--- Current Data ---\n");
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Disease: %s\n", patients[i].disease);
            printf("Doctor: %s\n", patients[i].doctor);
            printf("Admission Date: %s\n", patients[i].admissionDate);

            printf("\n--- Enter New Data ---\n");

            printf("Enter Name: ");
            scanf(" %[^\n]", patients[i].name);

            printf("Enter Age: ");
            scanf("%d", &patients[i].age);

            // Validate age again
            if (patients[i].age <= 0 || patients[i].age > 120) {
                printf("\nInvalid age!\n");
                return;
            }

            printf("Enter Disease: ");
            scanf(" %[^\n]", patients[i].disease);

            printf("Enter Doctor: ");
            scanf(" %[^\n]", patients[i].doctor);

            printf("Enter Admission Date: ");
            scanf(" %[^\n]", patients[i].admissionDate);

            // Validate date format
            if (!isValidDate(patients[i].admissionDate)) {
                printf("\nInvalid date format!\n");
                return;
            }

            printf("\nPatient updated successfully!\n");
            return;
        }
    }

    printf("\nPatient not found.\n");
}

void deletePatient() {
    int id;
    printf("\nEnter Patient ID to delete: ");
    scanf("%d", &id);

    // Find and remove the record
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {

            // Shift all elements left
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }

            patientCount--;

            printf("\nPatient deleted successfully!\n");
            return;
        }
    }

    printf("\nPatient not found.\n");
}

// Simple bubble sort by name
void sortByName() {
    if (patientCount < 2) {
        printf("\nNot enough records to sort.\n");
        return;
    }

    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = 0; j < patientCount - i - 1; j++) {
            if (strcmp(patients[j].name, patients[j+1].name) > 0) {
                struct Patient tmp = patients[j];
                patients[j] = patients[j+1];
                patients[j+1] = tmp;
            }
        }
    }

    printf("\nPatients sorted by Name (A-Z).\n");
}

// Sort by ID using bubble sort
void sortByID() {
    if (patientCount < 2) {
        printf("\nNot enough records to sort.\n");
        return;
    }

    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = 0; j < patientCount - i - 1; j++) {
            if (patients[j].id > patients[j+1].id) {
                struct Patient tmp = patients[j];
                patients[j] = patients[j+1];
                patients[j+1] = tmp;
            }
        }
    }

    printf("\nPatients sorted by ID.\n");
}
