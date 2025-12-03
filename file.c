#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

void loadFromFile() {
    FILE *fp = fopen("patients.txt", "r");
    if (!fp) return;  // File may not exist on first run

    struct Patient p;

    // Read CSV values from each line
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
        printf("File saving error!\n");
        return;
    }

    // Write all records back to file
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
