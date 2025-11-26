#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

/* Global dynamic array */
struct Patient *patients = NULL;
int patientCount = 0;
int capacity = 0;

void ensureCapacity() {
    if (patientCount == capacity) {
        capacity = (capacity == 0) ? 2 : capacity * 2;
        patients = realloc(patients, capacity * sizeof(struct Patient));
        if (!patients) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
}

void addPatient() {
    ensureCapacity();

    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);

    printf("Enter Doctor: ");
    scanf(" %[^\n]", p.doctor);

    printf("Enter Admission Date (YYYY-MM-DD): ");
    scanf(" %[^\n]", p.admissionDate);

    patients[patientCount++] = p;

    printf("\nPatient added successfully!\n");
}

void displayPatients() {
    if (patientCount == 0) {
        printf("\nNo patient records available.\n");
        return;
    }

    printf("\n--- All Patients ---\n");
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
    if (patientCount == 0) {
        printf("\nNo records available.\n");
        return;
    }

    int id;
    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

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

    printf("\nPatient with ID %d not found.\n", id);
}

void updatePatient() {
    if (patientCount == 0) {
        printf("\nNo records available.\n");
        return;
    }

    int id;
    printf("\nEnter Patient ID to update: ");
    scanf("%d", &id);

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

            printf("Enter Disease: ");
            scanf(" %[^\n]", patients[i].disease);

            printf("Enter Doctor: ");
            scanf(" %[^\n]", patients[i].doctor);

            printf("Enter Admission Date: ");
            scanf(" %[^\n]", patients[i].admissionDate);

            printf("\nPatient updated successfully!\n");
            return;
        }
    }

    printf("\nPatient with ID %d not found.\n", id);
}

void deletePatient() {
    if (patientCount == 0) {
        printf("\nNo records to delete.\n");
        return;
    }

    int id;
    printf("\nEnter Patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {

            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }

            patientCount--;

            printf("\nPatient deleted successfully!\n");
            return;
        }
    }

    printf("\nPatient with ID %d not found.\n", id);
}
