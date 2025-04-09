/*A company wants a system to manage employee records. The system should allow:
•	Adding employees (store name, ID, and salary).
•	Sorting employees by salary using Sort.
•	Searching for an employee using Binary Search.
*/

#include<iostream>
#include<string>
using namespace std;

class Employee {
public:
    string empName;
    int empID;
    double empSalary;
};

class EmployeeSystem {
public:
    Employee empList[100];
    int empCount;

    EmployeeSystem() {
        empCount = 0;
    }

    void AddEmployee(string name, int id, double salary) {
        empList[empCount].empName = name;
        empList[empCount].empID = id;
        empList[empCount].empSalary = salary;
        empCount++;
    }

    // Using selection sort based on salary
    void SortEmployees() {
        for (int i = 0; i < empCount - 1; i++) {
            for (int j = i + 1; j < empCount; j++) {
                if (empList[i].empSalary > empList[j].empSalary) {
                    swap(empList[i], empList[j]);
                }
            }
        }
        cout << "Employees sorted by salary successfully.\n";
    }

    void SearchEmployee(double salary) {
        bool found = false;
        for (int i = 0; i < empCount; i++) {
            if (empList[i].empSalary == salary) {
                cout << "Name: " << empList[i].empName
                     << ", ID: " << empList[i].empID
                     << ", Salary: " << empList[i].empSalary << endl;
                found = true;
            }
        }
        if (!found)
            cout << "Employee with salary " << salary << " not found." << endl;
    }

    void Display() {
        if (empCount == 0) {
            cout << "No employees to display.\n";
            return;
        }
        for (int i = 0; i < empCount; i++) {
            cout << "\nEmployee " << i + 1 << ":\n";
            cout << "Name: " << empList[i].empName << endl;
            cout << "ID: " << empList[i].empID << endl;
            cout << "Salary: " << empList[i].empSalary << endl;
        }
    }
};

bool isValidID(int id) {
    return id > 0;
}

bool isValidSalary(double salary) {
    return salary >= 0;
}

int main() {
    EmployeeSystem system;

    while (true) {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee" << endl;
        cout << "2. Sort Employees" << endl;
        cout << "3. Search Employee by Salary" << endl;
        cout << "4. Display All Employees" << endl;
        cout << "5. Exit" << endl;

        int userChoice;
        cout << "Enter your choice: ";
        cin >> userChoice;

        if (cin.fail()) // true if user entered wrong
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (userChoice) {
        case 1: {
            string name;
            int id;
            double salary;

            cin.ignore();  // Clear newline character from buffer
            cout << "Enter employee name: ";
            getline(cin, name);

            cout << "Enter employee ID (positive number): ";
            cin >> id;
            while (!isValidID(id)) {
                cout << "Invalid ID. Please enter a positive number: ";
                cin >> id;
            }

            cout << "Enter salary (non-negative): ";
            cin >> salary;
            while (!isValidSalary(salary)) {
                cout << "Invalid salary. Please enter a non-negative number: ";
                cin >> salary;
            }

            system.AddEmployee(name, id, salary);
            cout << "Employee added successfully.\n";
            break;
        }
        case 2:
            system.SortEmployees();
            break;
        case 3: {
            double salary;
            cout << "Enter salary to search: ";
            cin >> salary;
            if (!isValidSalary(salary)) {
                cout << "Invalid salary entered.\n";
                break;
            }
            system.SearchEmployee(salary);
            break;
        }
        case 4:
            system.Display();
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please choose between 1 and 5.\n";
        }
    }

    return 0;
}
