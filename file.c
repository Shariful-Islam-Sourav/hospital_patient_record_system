#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

// Access variables from patient.c
extern struct Patient *patients;
extern int patientCount;
extern int capacity;

// Load data from file
void loadFromFile() {
    FILE *fp = fopen("patients.txt", "r");
    if (!fp) {
        printf("Starting with an empty database.\n");
        return;
    }

    capacity = 10;
    patients = malloc(sizeof(struct Patient) * capacity);
    patientCount = 0;

    while (!feof(fp)) {
        struct Patient p;
        int r = fscanf(fp, "%d,%49[^,],%d, %9[^,],%49[^,],%49[^,],%14[^\n]\n",
                       &p.id,
                       p.name,
                       &p.age,
                       p.blood,
                       p.diseas,
                       p.doctor,
                       p.admissionDate);

        if (r == 6) {
            if (patientCount >= capacity) {
                capacity *= 2;
                patients = realloc(patients, sizeof(struct Patient) * capacity);
            }
            patients[patientCount++] = p;
        }
    }

    fclose(fp);
}

// Save data to file
void saveToFile() {
    FILE *fp = fopen("patients.txt", "w");
    if (!fp) {
        printf("Error: Could not save file.\n");
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        fprintf(fp, "%d,%s,%d,%s,%s,%s\n",
                patients[i].id,
                patients[i].name,
                patients[i].age,
                patients[i].diseas,
                patients[i].doctor,
                patients[i].admissionDate);
    }

    fclose(fp);
    printf("\nData saved successfully.\n");
}
