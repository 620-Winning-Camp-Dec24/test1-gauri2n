#include <iostream>
using namespace std;

// Base class
class Student {
public:
    int rollNo;
    string name;
};

// Derived class
class Result : public Student {
public:
    float marks[3];

    void calculateAndDisplayResult() {
        float total = marks[0] + marks[1] + marks[2];
        float percentage = (total / 300) * 100;

        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Result student;

    // Input student details
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, student.name);

    // Input marks
    cout << "Enter marks for three subjects:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Subject " << i + 1 << ": ";
        cin >> student.marks[i];
    }

    // Display result
    cout << "\nResult:\n";
    student.calculateAndDisplayResult();

    return 0;
}