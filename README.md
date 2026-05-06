# Student Management System
A console-based Student Management System written in C++ that demonstrates core Object-Oriented Programming concepts.

---

## Concepts Used
- **Abstraction** – using an abstract `display` class with a pure virtual function
- **Inheritance** – `person` inherits from `display`, `student` inherits from `person`
- **Polymorphism** – storing `student` objects in a `vector<person*>` and calling `displayIDinfo()` through base class pointers
- **Encapsulation** – data is kept `private`/`protected` and accessed through getters and setters

---

## Features
- Add a student (name, net ID, CGPA, marks)
- View all students in a formatted table
- Delete a student by net ID
- CGPA validation (must be between 1.0 and 10.0)

---

## How to Run

**Compile:**
```bash
g++ student_management.cpp -o student_management
```

**Run:**
```bash
./student_management
```

---

## Sample Output
```
-------STUDENT MANAGEMENT SYSTEM----------
1. ADD STUDENT
2. VIEW STUDENTS
3. DELETE STUDENT
4. EXIT

NAME                NET ID         CGPA      MARKS
----------------------------------------------------
Sujoy Behera        sb8449         8.5       920
JOHN  WICK           jh007         9.1       875
```

---

## Project Structure
```
├── student_management.cpp   # main source file
└── README.md
```

---

## Author
Made by SUJOY BEHERA as part of learning OOP in C++.
