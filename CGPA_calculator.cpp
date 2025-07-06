#include <iostream>
#include <vector>
using namespace std;

// Class to represent a subject
class Subject {
public:
    string subname; // name of the subject
    int credit; // credit of the subject
    float gradepoint; // grade point of the subject

    // Constructor to initialize the subject
    Subject(string name, int cr, float gp) {
        subname = name;
        credit = cr;
        gradepoint = gp;
    }
};

// Class to represent a student
class Student {
    string name; // name of the student
    vector<Subject> subjects; // vector to store the subjects of the student

public:
    // Constructor to initialize the student
    Student(string sname) {
        name = sname;
    }

    // Function to add a subject to the student
    void addSubject(string subname, int credit, float gradepoint) {
        Subject newSubject(subname, credit, gradepoint);
        subjects.push_back(newSubject);
    }

    // Function to calculate the CGPA of the student
    float calculateCGPA() {
        int totalCredit = 0; // total credit of the student
        float weightedGradePoint = 0; // weighted grade point of the student
        for (const Subject &subject : subjects) {
            totalCredit += subject.credit;
            weightedGradePoint += subject.credit * subject.gradepoint;
        }
        return (totalCredit > 0) ? (weightedGradePoint / totalCredit) : 0;
    }

    // Function to display the CGPA of the student
    void displayCGPA() {
        cout << "\nStudent name: " << name << endl;
        float cgpa = calculateCGPA();
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    string studentName;
    int numSubjects;

    cout << "Enter student's name: ";
    getline(cin, studentName);

    cout << "Enter the number of subjects: ";
    cin >> numSubjects;
    cin.ignore(); // clear newline character left in input buffer

    Student s(studentName);

    for (int i = 0; i < numSubjects; i++) {
        string subname;
        int credit;
        float gradepoint;

        cout << "\nEnter subject name: ";
        getline(cin, subname);

        cout << "Enter credit: ";
        cin >> credit;

        cout << "Enter grade point: ";
        cin >> gradepoint;
        cin.ignore(); // clear buffer

        s.addSubject(subname, credit, gradepoint);
    }

    s.displayCGPA();
    return 0;
}
