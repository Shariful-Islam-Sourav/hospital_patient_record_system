#ifndef PATIENT_H
#define PATIENT_H

struct Patient {
    int id;
    char name[100];
    int age;
    char disease[100];
    char doctor[100];
    char admissionDate[20];
};

/* Extern variables */
extern struct Patient *patients;
extern int patientCount;
extern int capacity;

/* Core functions */
void ensureCapacity();
void addPatient();
void displayPatients();
void searchPatient();
void updatePatient();
void deletePatient();

/* File I/O functions */
void loadFromFile();
void saveToFile();

#endif
