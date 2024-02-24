#include <iostream>
#include <string>

using namespace std;

// Rule 1: Class Student
class Student {
protected:
    string name;
    int id;
    string phone;
private:
    float cgpa;
public:
    string address;
    string dob;

public:
    Student() {}

    Student(string n, int i, string ph, string addr, string dob) : name(n), id(i), phone(ph), address(addr), dob(dob) {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Date of Birth: " << dob << endl;
    }

    void setPhone(string ph) {
        phone = ph;
    }

    ~Student() {
        // Destructor
    }
};

// Rule 2: Class Discipline
class Discipline {
protected:
    int attendance;
    int punishmentCount;
    int classPerformance;

public:
    Discipline() {}

    Discipline(int att, int punish, int cp) : attendance(att), punishmentCount(punish), classPerformance(cp) {}

    void display() {
        cout << "Attendance: " << attendance << "/5" << endl;
        cout << "Punishment Count: " << punishmentCount << "/10" << endl;
        cout << "Class Performance: " << classPerformance << "/5" << endl;
    }

    int calculateAdditionalMarks() {
        return attendance + classPerformance - punishmentCount;
    }

    ~Discipline() {
        // Destructor
    }
};

// Rule 3: Class Marks
class Marks : private Student, private Discipline {
private:
    int sub1, sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9;

public:
    Marks() {}

    Marks(string n, int i, string ph, string addr, string dob, int att, int punish, int cp,
          int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8, int s9)
            : Student(n, i, ph, addr, dob), Discipline(att, punish, cp),
              sub1(s1), sub2(s2), sub3(s3), sub4(s4), sub5(s5), sub6(s6), sub7(s7), sub8(s8), sub9(s9) {}

    void computeTotalMarks() {
        int totalSubjectMarks = sub1 + sub2 + sub3 + sub4 + sub5 + sub6 + sub7 + sub8 + sub9;
        int averageSubjectMarks = totalSubjectMarks / 9;
        int additionalMarks = calculateAdditionalMarks(); // Calculate additional marks from Discipline class
        int totalMarks = averageSubjectMarks + (additionalMarks / 10); // Total marks out of 100

        cout << "Total Marks: " << totalMarks << "/100" << endl;
    }

    void displayMarks() {
        Student::display(); // Call display() function from Student class
        Discipline::display(); // Call display() function from Discipline class

        cout << "Subject 1: " << sub1 << endl;
        cout << "Subject 2: " << sub2 << endl;
        cout << "Subject 3: " << sub3 << endl;
        cout << "Subject 4: " << sub4 << endl;
        cout << "Subject 5: " << sub5 << endl;
        cout << "Subject 6: " << sub6 << endl;
        cout << "Subject 7: " << sub7 << endl;
        cout << "Subject 8: " << sub8 << endl;
        cout << "Subject 9: " << sub9 << endl;
    }

    ~Marks() {
        // Destructor
    }
};

int main() {
    // Example usage
    Marks student("Foyez", 181400106, "1234567890", "Dhaka", "2000-01-01", 4, 2, 4, 80, 85, 75, 90, 85, 80, 70, 90, 75);
    student.displayMarks();
    student.computeTotalMarks();

    return 0;
}
