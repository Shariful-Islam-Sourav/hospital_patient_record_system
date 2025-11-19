#ifndef PATIENT_H
#define PATIENT_H

struct Patient {
    int id;
    char name[50];
    int age;
    char blood[10];
    char diseas[50];
    char doctor[50];
    char admissionDate[15];
};

// Shared variables (declared in patient.c)
extern struct Patient *patients;
extern int patientCount;
extern int capacity;

// Core functions
void initMemory();
void addPatient();
void displayPatients();

// File operations
void loadFromFile();
void saveToFile();

#endif
