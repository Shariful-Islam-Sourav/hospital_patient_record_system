#include<stdio.h>
#include "patient.h"
#include<stdlib.h>

struct Patient *patients = NULL;
int patientCount = 0;
int capacity = 0;

void initMemory() {
    capacity = 10;
    patients = malloc(sizeof(struct Patient) * capacity);
}

void addPatient() {
    if (patientCount >= capacity) {
        capacity *= 2;
        patients = realloc(patients, sizeof(struct Patient) * capacity);
    }

    struct Patient p;

    printf("Enter ID: ");
    scanf("%d", &p.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Blood Group: ");
    scanf(" %[^\n]", p.blood);

    printf("Enter Disease: ");
    scanf(" %[^\n]", p.diseas);

    printf("Enter Doctor Name: ");
    scanf(" %[^\n]", p.doctor);

    printf("Enter Admission Date (YYYY-MM-DD): ");
    scanf(" %[^\n]", p.admissionDate);

    patients[patientCount++] = p;

    printf("\nPatient added successfully!\n");
}

void displayPatients() {
    if (patientCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n---- All Patient Records ----\n");

    for (int i = 0; i < patientCount; i++) {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nID: %d", patients[i].id);
        printf("\nName: %s", patients[i].name);
        printf("\nAge: %d", patients[i].age);
        printf("\nName: %s", patients[i].blood);
        printf("\nDisease: %s", patients[i].diseas);
        printf("\nDoctor: %s", patients[i].doctor);
        printf("\nAdmission Date: %s\n", patients[i].admissionDate);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
}
