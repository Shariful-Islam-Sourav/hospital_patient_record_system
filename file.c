#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

void loadFromFile() {
    FILE *fp = fopen("patients.txt", "r");
    if (!fp) return;

    struct Patient p;

    while (fscanf(fp, "%d,%99[^,],%d,%99[^,],%99[^,],%19[^\n]\n",
                  &p.id, p.name, &p.age, p.disease, p.doctor, p.admissionDate) == 6) {

        ensureCapacity();
        patients[patientCount++] = p;
    }

    fclose(fp);
}

void saveToFile() {
    FILE *fp = fopen("patients.txt", "w");
    if (!fp) {
        printf("\nError saving file.\n");
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        fprintf(fp, "%d,%s,%d,%s,%s,%s\n",
                patients[i].id,
                patients[i].name,
                patients[i].age,
                patients[i].disease,
                patients[i].doctor,
                patients[i].admissionDate);
    }

    fclose(fp);
    printf("\nData saved successfully.\n");
}
