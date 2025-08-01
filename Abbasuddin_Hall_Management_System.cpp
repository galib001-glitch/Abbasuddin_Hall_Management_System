#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ======== Base Class ========
class Person {
protected:
    string name;
    string contact;
public:
    void inputBasicInfo() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Contact: ";
        getline(cin, contact);
    }
    void showBasicInfo() {
        cout << "Name: " << name << " | Contact: " << contact << endl;
    }
};

// ======== STUDENT CLASS ========
class Student : public Person {
    string roll;
    string department;
    int year;
    int roomNo;
    bool feesPaid;
    string complaint;
public:
    void inputStudent() {
        inputBasicInfo();
        cout << "Enter Roll No: ";
        getline(cin, roll);
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Room No: ";
        cin >> roomNo;
        cin.ignore();
        cout << "Fees Paid? (1 for Yes, 0 for No): ";
        cin >> feesPaid;
        cin.ignore();
        cout << "Any Complaint (write 'None' if no complaint): ";
        getline(cin, complaint);
    }

    void showStudent() {
        cout << left << setw(15) << name 
             << setw(12) << roll 
             << setw(15) << department 
             << setw(6) << year 
             << setw(8) << roomNo 
             << setw(8) << (feesPaid ? "Paid" : "Due")
             << setw(20) << complaint << endl;
    }

    void writeToFile(ofstream &out) {
        out << name << "|" << contact << "|" << roll << "|" << department << "|" 
            << year << "|" << roomNo << "|" << feesPaid << "|" << complaint << "\n";
    }

    bool readFromFile(string line) {
        size_t pos = 0;
        vector<string> tokens;
        while ((pos = line.find('|')) != string::npos) {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);
        if (tokens.size() < 8) return false;
        name = tokens[0];
        contact = tokens[1];
        roll = tokens[2];
        department = tokens[3];
        year = stoi(tokens[4]);
        roomNo = stoi(tokens[5]);
        feesPaid = stoi(tokens[6]);
        complaint = tokens[7];
        return true;
    }
};

// ======== STAFF CLASS ========
class Staff : public Person {
    string position;
    int attendance;
    double salaryPerDay;
public:
    void inputStaff() {
        inputBasicInfo();
        cout << "Enter Position (Cook/Cleaner/Guard): ";
        getline(cin, position);
        cout << "Enter Attendance Days: ";
        cin >> attendance;
        cout << "Enter Salary Per Day: ";
        cin >> salaryPerDay;
        cin.ignore();
    }

    void showStaff() {
        cout << left << setw(15) << name 
             << setw(15) << position 
             << setw(10) << attendance 
             << setw(10) << salaryPerDay 
             << setw(10) << (attendance * salaryPerDay) << endl;
    }

    void writeToFile(ofstream &out) {
        out << name << "|" << contact << "|" << position << "|" << attendance << "|" << salaryPerDay << "\n";
    }

    bool readFromFile(string line) {
        size_t pos = 0;
        vector<string> tokens;
        while ((pos = line.find('|')) != string::npos) {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);
        if (tokens.size() < 5) return false;
        name = tokens[0];
        contact = tokens[1];
        position = tokens[2];
        attendance = stoi(tokens[3]);
        salaryPerDay = stod(tokens[4]);
        return true;
    }
};

// ======== DINING CLASS ========
class Dining {
    string roll;
    int breakfast;
    int lunch;
    int dinner;
public:
    Dining() : breakfast(0), lunch(0), dinner(0) {}

    void inputDining() {
        cout << "Enter Student Roll No: ";
        cin >> roll;
        cout << "Enter Breakfast Count: ";
        cin >> breakfast;
        cout << "Enter Lunch Count: ";
        cin >> lunch;
        cout << "Enter Dinner Count: ";
        cin >> dinner;
    }

    void showDining() {
        cout << left << setw(12) << roll 
             << setw(10) << breakfast 
             << setw(10) << lunch 
             << setw(10) << dinner 
             << setw(10) << (breakfast*20 + lunch*50 + dinner*50) << endl;
    }

    void writeToFile(ofstream &out) {
        out << roll << "|" << breakfast << "|" << lunch << "|" << dinner << "\n";
    }

    bool readFromFile(string line) {
        size_t pos = 0;
        vector<string> tokens;
        while ((pos = line.find('|')) != string::npos) {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);
        if (tokens.size() < 4) return false;
        roll = tokens[0];
        breakfast = stoi(tokens[1]);
        lunch = stoi(tokens[2]);
        dinner = stoi(tokens[3]);
        return true;
    }
};

// ======== VISITOR CLASS ========
class Visitor {
    string name;
    string whomToVisit;
    string date;
public:
    void inputVisitor() {
        cin.ignore();
        cout << "Enter Visitor Name: ";
        getline(cin, name);
        cout << "Whom to Visit (Student Roll/Teacher Name): ";
        getline(cin, whomToVisit);
        cout << "Enter Date (DD-MM-YYYY): ";
        getline(cin, date);
    }

    void showVisitor() {
        cout << left << setw(15) << name << setw(20) << whomToVisit << setw(15) << date << endl;
    }

    void writeToFile(ofstream &out) {
        out << name << "|" << whomToVisit << "|" << date << "\n";
    }

    bool readFromFile(string line) {
        size_t pos = 0;
        vector<string> tokens;
        while ((pos = line.find('|')) != string::npos) {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);
        if (tokens.size() < 3) return false;
        name = tokens[0];
        whomToVisit = tokens[1];
        date = tokens[2];
        return true;
    }
};

// ======== FILE HELPERS ========
template <typename T>
vector<T> loadData(const string &filename) {
    vector<T> data;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        T item;
        if (item.readFromFile(line)) {
            data.push_back(item);
        }
    }
    in.close();
    return data;
}

template <typename T>
void saveData(const string &filename, vector<T> &data) {
    ofstream out(filename);
    for (T &item : data) {
        item.writeToFile(out);
    }
    out.close();
}

// ======== MENUS ========
void studentMenu() {
    vector<Student> students = loadData<Student>("students.dat");
    int choice;
    do {
        cout << "\n===== STUDENT MANAGEMENT =====\n";
        cout << "1. Add Student\n2. Show All Students\n3. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Student s;
            s.inputStudent();
            students.push_back(s);
            saveData("students.dat", students);
            cout << "✅ Student Added!\n";
        } else if (choice == 2) {
            cout << left << setw(15) << "Name" << setw(12) << "Roll" 
                 << setw(15) << "Dept" << setw(6) << "Year" 
                 << setw(8) << "Room" << setw(8) << "Fees" 
                 << setw(20) << "Complaint" << endl;
            for (Student &s : students) {
                s.showStudent();
            }
        }
    } while (choice != 3);
}

void staffMenu() {
    vector<Staff> staffList = loadData<Staff>("staff.dat");
    int choice;
    do {
        cout << "\n===== STAFF MANAGEMENT =====\n";
        cout << "1. Add Staff\n2. Show All Staff\n3. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Staff st;
            st.inputStaff();
            staffList.push_back(st);
            saveData("staff.dat", staffList);
            cout << "✅ Staff Added!\n";
        } else if (choice == 2) {
            cout << left << setw(15) << "Name" << setw(15) << "Position" 
                 << setw(10) << "Days" << setw(10) << "Rate" 
                 << setw(10) << "Salary" << endl;
            for (Staff &st : staffList) {
                st.showStaff();
            }
        }
    } while (choice != 3);
}

void diningMenu() {
    vector<Dining> diningList = loadData<Dining>("dining.dat");
    int choice;
    do {
        cout << "\n===== DINING MANAGEMENT =====\n";
        cout << "1. Record Meals\n2. Show Dining Report\n3. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Dining d;
            d.inputDining();
            diningList.push_back(d);
            saveData("dining.dat", diningList);
            cout << "✅ Dining record added!\n";
        } else if (choice == 2) {
            cout << left << setw(12) << "Roll" 
                 << setw(10) << "Breakfast" 
                 << setw(10) << "Lunch" 
                 << setw(10) << "Dinner" 
                 << setw(10) << "Bill (৳)" << endl;
            for (Dining &d : diningList) {
                d.showDining();
            }
        }
    } while (choice != 3);
}

void visitorMenu() {
    vector<Visitor> visitors = loadData<Visitor>("visitors.dat");
    int choice;
    do {
        cout << "\n===== VISITOR RECORDS =====\n";
        cout << "1. Add Visitor\n2. Show Visitor Log\n3. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Visitor v;
            v.inputVisitor();
            visitors.push_back(v);
            saveData("visitors.dat", visitors);
            cout << "✅ Visitor Added!\n";
        } else if (choice == 2) {
            cout << left << setw(15) << "Visitor" << setw(20) << "Whom To Visit" << setw(15) << "Date" << endl;
            for (Visitor &v : visitors) {
                v.showVisitor();
            }
        }
    } while (choice != 3);
}

// ======== MAIN MENU ========
int main() {
    int choice;
    do {
        cout << "\n========== ABBASUDDIN AHMED HALL MANAGEMENT ==========\n";
        cout << "1. Student Management\n";
        cout << "2. Staff Management\n";
        cout << "3. Dining Management\n";
        cout << "4. Visitor Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: studentMenu(); break;
            case 2: staffMenu(); break;
            case 3: diningMenu(); break;
            case 4: visitorMenu(); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
