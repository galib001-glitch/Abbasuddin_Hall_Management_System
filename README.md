"# Abbasuddin_Hall_Management_System" 
#  Abbasuddin Ahmed Hall Management System (C++)

A **C++ console-based management system** for **Abbasuddin Ahmed Hall** at BAUST.
This project helps manage **students, staff, dining, visitors, and more** using **Object-Oriented Programming (OOP)** and **file handling**.

---

##  Features

 **Student Management**

* Add new students with roll, department, year, and room number
* Track fees status (Paid/Due)
* Store complaints for resolution

 **Staff Management**

* Add staff (cook, cleaner, guard, etc.)
* Track attendance
* Auto-calculate monthly salary

 **Dining Management**

* Record meals (breakfast, lunch, dinner) for each student
* Calculate total monthly meal bill automatically

 **Visitor Records**

* Store visitor details (who they visited and date)
* View past visitor logs

✅ **Persistent Storage**

* Data saved in text-based `.dat` files:

  * `students.dat`
  * `staff.dat`
  * `dining.dat`
  * `visitors.dat`

---

##  Project Structure

```
 Abbasuddin-Ahmed-Hall-Management/
├── hall_management.cpp   # Main C++ source code
├── students.dat          # Auto-created file for students
├── staff.dat             # Auto-created file for staff
├── dining.dat            # Auto-created file for dining info
├── visitors.dat          # Auto-created file for visitors
└── README.md             # Project description
```

---

##  How to Run

1️ **Clone the repo**

```bash
git clone https://github.com/YOUR_USERNAME/Abbasuddin-Ahmed-Hall-Management.git
cd Abbasuddin-Ahmed-Hall-Management
```

2️ **Compile the program**

```bash
g++ hall_management.cpp -o hall_system
```

3️ **Run the program**

```bash
./hall_system
```

---

 🎯 Usage

When you run the program, you’ll see a menu:

```
========== ABBASUDDIN AHMED HALL MANAGEMENT ==========
1. Student Management
2. Staff Management
3. Dining Management
4. Visitor Records
5. Exit
```

* Choose a section to manage students, staff, dining, or visitor logs.

---

##  Future Features (Planned)

* Room Allocation System (track vacant/occupied rooms)
* Finance Report (total income & expenses)
* Complaint Resolution System
* Admin/Student Login System

---

##  Tech Stack

* **Language:** C++
* **Concepts Used:** Classes, Inheritance, File Handling, Menus
* **Platform:** Console Application

---

##  Author

**Abdullah Al Galib Tonmoy**
 BAUST – Bangladesh Army University of Science and Technology

---
