<b> MediRecord System — Hospital Patient Record Manager </b>

A modular C program for managing hospital patient information using dynamic memory, file handling, and structured data management.
Developed as part of the Advanced C Programming course project.

📌 Project Overview
MediRecord System is a console-based hospital patient record manager built in the C language.
It allows hospital staff to store, display, and persist patient information through file handling.
The project demonstrates key advanced C programming concepts such as dynamic memory allocation, pointers, structures, modular programming, and file I/O.


✨ Key Features
➕ Add new patient records
📄 Display all stored patient records
💾 Save all patient data to a file
📂 Load previous session data automatically
🧩 Modular program structure (multiple .c files + .h header)
🧠 Dynamic memory allocation (malloc, realloc)
📌 No global variables (uses extern + separate module management)


📁 Project Structure
MediRecord_System/
│
├── main.c          # Program entry point and menu system
├── patient.c       # Patient operations (add, display)
├── file.c          # File load/save logic
├── patient.h       # Header with structs & function declarations
└── patients.txt    # Data storage file (auto-created)


🧱 Technologies & Concepts Used
C Programming Language
Structures (struct)
Pointers
Dynamic Memory Allocation (malloc, realloc, free)
File Handling (text file read/write)
Modular Programming (separate .c and .h files)
Menu-Driven Interface

🏗️ Compilation Instructions
Using GCC (Recommended)
Open terminal / CMD inside the project folder:

gcc main.c patient.c file.c -o medirecord
If no errors → run the program:

Windows:
medirecord.exe
Mac/Linux:
./medirecord

🖥️ How to Use
After running the program, you will see the menu:

--- MediRecord System ---
1. Add Patient
2. Display All Patients
3. Save & Exit
Enter your choice:

🕹️Available Operations:

Add Patient
Enter patient details (ID, Name, Age, Disease, Doctor, Admission Date).

Display All Patients
Shows all records currently in memory.

Save & Exit
Saves all data to patients.txt and exits safely.

🗂️ Data Storage Format
The application stores data in a human-readable text file:

Example (patients.txt):
1,John Smith,45,Flu,Dr. Kim,2025-11-05
2,Alice Park,30,Allergy,Dr. Lee,2025-11-06


🧪 Testing Guide
Start the program → choose option 1 to add sample patients
Use option 2 to confirm they are stored correctly
Use 3 to save & exit
Restart the program → data should load automatically (loadFromFile working)
