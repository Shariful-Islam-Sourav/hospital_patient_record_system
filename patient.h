#ifndef PATIENT_H
#define PATIENT_H

// Structure to store all patient information
struct Patient {
    int id;
    char name[100];
    int age;
    char disease[100];
    char doctor[100];
    char admissionDate[20];
};

// Variables declared globally but defined in patient.c
extern struct Patient *patients;
extern int patientCount;
extern int capacity;

// Core functions
void ensureCapacity();
void addPatient();
void displayPatients();
void searchPatient();
void updatePatient();
void deletePatient();

// Sorting functions
void sortByName();
void sortByID();

// File handling
void loadFromFile();
void saveToFile();

#endif
