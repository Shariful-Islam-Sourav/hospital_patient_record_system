

# **MediRecord System — Hospital Patient Record Manager**

A modular C application for managing hospital patient records using dynamic memory, file handling, and structured data management.
Developed for the **Advanced C Programming** course project.

---

## 📌 **Project Overview**

MediRecord System is a console-based patient management system designed to store, retrieve, update, search, and delete hospital patient records.
The project demonstrates the use of:

* Modular C-programming
* Dynamic memory allocation (`malloc`, `realloc`)
* Structures
* Pointers
* File handling
* Menu-driven interfaces

This project was built phase-by-phase across multiple weeks.

---


## 📁 **Project Structure**

```
MediRecord_System/
│
├── main.c          # Main menu and controller
├── patient.c       # Add, display, search, update, delete functions
├── file.c          # Save/load file operations
├── patient.h       # Struct definition and function prototypes
└── patients.txt    # Auto-generated file for persistent storage
```

---

## 🧱 **Technologies & Concepts Used**

* C programming language
* Structures (`struct Patient`)
* Pointers
* Dynamic memory allocation
* Modular programming
* Scanf advanced format specifiers (`%[^\n]`)
* File handling using text files
* String manipulation (`strcpy`, `fscanf`)

---

## 🏗️ **Compilation Instructions**

### **Using GCC**

Run this in your project directory:

```
gcc main.c patient.c file.c -o medirecord
```

### **Run the Program**

**Windows**

```
medirecord.exe
```

**Linux/macOS**

```
./medirecord
```

---

## 🖥️ **How to Use**

After running, you will see:

```
--- MediRecord System ---
1. Add Patient
2. Display All Patients
3. Save & Exit
4. Search Patient
5. Update Patient
6. Delete Patient
Enter your choice:
```

### Available Operations:

#### ➕ Add Patient

Enter details like ID, Name, Age, Disease, Doctor, Admission Date.

#### 📄 Display All Patients

Lists all stored patients.

#### 🔍 Search Patient

Search by ID.

#### ✏️ Update Patient

Modify existing patient details.

#### ❌ Delete Patient

Removes a patient and reorganizes the list.

#### 💾 Save & Exit

Saves the entire dataset to **patients.txt** and exits.

---

## 🗂️ **Data Storage Format**

Example content of `patients.txt`:

```
101,John Doe,45,Flu,Dr. Kim,2025-11-02
102,Alice Park,30,Allergy,Dr. Lee,2025-11-05
103,Mahmud Hasan,51,Diabetes,Dr. Choi,2025-11-06
```

* Stored in CSV-like format
* Easy to read and modify
* Automatically loaded on application start

---

## 👨‍💻 **Author**

**Sourav Md Shariful Islam**
Computer Science & Engineering
Sejong University

