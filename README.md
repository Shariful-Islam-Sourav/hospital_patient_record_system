# MediRecord System — Hospital Patient Record Manager

**A modular C application for managing hospital patient records using dynamic memory, file handling, sorting, validation, and structured data management.**

> **Note:** Developed for the *Advanced C Programming* course project.

---

## 📌 Project Overview

**MediRecord System** is a console-based patient management system designed to store, retrieve, search, update, delete, and sort hospital patient records.

The project demonstrates the use of:
* **Modular C programming**
* **Dynamic memory allocation** (`malloc`, `realloc`, `free`)
* **Structures** (`struct`) and **Pointers**
* **File handling** (Persistent storage)
* **Sorting algorithms** (Bubble Sort)
* **Input validation** and Menu-driven interfaces

*This project was completed in multiple phases across four weeks.*

---

## ✨ Features (Final Week 4 Version)

* [x] **Add new patient record**
* [x] **Display all patients**
* [x] **Search patient by ID**
* [x] **Update patient information**
* [x] **Delete patient** (with array shifting)
* [x] **Sort patients by Name** (A–Z)
* [x] **Sort patients by ID** (Ascending)
* [x] **File save & load** (Auto-persistence)
* [x] **Validation** (Date format, Duplicate IDs)
* [x] **Memory cleanup** (No memory leaks)

---

## 📁 Project Structure

```text
MediRecord_System/
│
├── main.c          # Main menu and controller
├── patient.c       # Add, display, search, update, delete, sort functions
├── file.c          # Save/load file operations
├── patient.h       # Struct definition and function prototypes
└── patients.txt    # Auto-generated file for persistent storage
````

-----

## 🧱 Technologies & Concepts Used

  * **Language:** C Programming
  * **Data Structures:** Structures (`struct Patient`), Arrays of Structures
  * **Memory:** Pointers, Dynamic Memory Allocation
  * **Algorithms:** Bubble Sort
  * **I/O:** Scanf input handling (`%[^\n]`), File I/O (`fscanf`, `fprintf`)
  * **String Manipulation:** `strcmp`, `strcpy`

-----

## 🏗️ Compilation Instructions

### Using GCC

Open your terminal in the project directory and run:

```bash
gcc main.c patient.c file.c -o medirecord
```

### Run the Program

**Windows:**

```bash
medirecord.exe
```

**Linux/macOS:**

```bash
./medirecord
```

-----

## 🖥️ How to Use

[Image of console based application menu interface]

After running the executable, you will see the main menu:

```text
--- MediRecord System ---
1. Add Patient
2. Display All Patients
3. Save & Exit
4. Search Patient
5. Update Patient
6. Delete Patient
7. Sort by Name (A-Z)
8. Sort by ID

Enter your choice:
```

### Available Operations

  * **➕ Add Patient:** Enter details like ID, Name, Age, Disease, Doctor, and Admission Date.
  * **📄 Display All Patients:** Shows all stored records in a tabular format.
  * **🔍 Search Patient:** Find a specific patient by their unique ID.
  * **✏️ Update Patient:** Modify selected fields for an existing patient.
  * **❌ Delete Patient:** Removes a record and automatically shifts the remaining array elements.
  * **🔤 Sort by Name:** Sorts records alphabetically (A-Z) using Bubble Sort.
  * **🔢 Sort by ID:** Sorts patients from lowest to highest ID number.
  * **💾 Save & Exit:** Saves all records to `patients.txt`, frees memory, and exits.

-----

## 🗂️ Data Storage Format

The data is stored in a CSV-like format in `patients.txt`. It is automatically loaded when the program starts.

**Sample `patients.txt` content:**

```csv
101,John Doe,45,Flu,Dr. Kim,2025-11-02
102,Alice Park,30,Allergy,Dr. Lee,2025-11-05
103,Mahmud Hasan,51,Diabetes,Dr. Choi,2025-11-06
```

-----

## ✔️ Validation Rules

1.  **Patient ID:** Must be unique (duplicates are rejected).
2.  **Age:** Must be between **1–120**.
3.  **Date:** Must follow the **YYYY-MM-DD** format.
4.  **Strings:** Names and diseases allow spaces.

-----

## 🧹 Memory Management

The system ensures robust memory handling. Before exiting, the program releases all allocated heap memory to prevent leaks:

```c
free(patients);
```

-----

## 👨‍💻 Author

**Sourav Md Shariful Islam**
*Computer Science & Engineering*
*Sejong University*

```

```