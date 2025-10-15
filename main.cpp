
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Address {
private:
    std::string street, city, state, zip;

public:
    void init(const std::string& st, const std::string& c, const std::string& s, const std::string& z) {
        street = st;
        city = c;
        state = s;
        zip = z;
    }//End init

    void printAddress() const {
        std::cout << street << "\n" << city << ", " << state << " " << zip << std::endl;
    }//End printAddress

};//End class Address Class

class Date {
private:
    std::string dateStr;

public:
    void init(const std::string& ds) {
        dateStr = ds;
    }//End init

    void printDate() const {
        std::cout << dateStr << std::endl;
    }//End printDate

};//End class Date

class Student {
private:
    std::string firstName, lastName;
    Address address;
    Date birthDate, gradDate;
    int credits;

public:
    void init(const std::string& data) {
        std::stringstream ss(data);
        std::string street, city, state, zip, birth, grad, creditStr;

        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, street, ',');
        std::getline(ss, city, ',');
        std::getline(ss, state, ',');
        std::getline(ss, zip, ',');
        std::getline(ss, birth, ',');
        std::getline(ss, grad, ',');
        std::getline(ss, creditStr);

        credits = std::stoi(creditStr);
        address.init(street, city, state, zip);
        birthDate.init(birth);
        gradDate.init(grad);
    }//End init

    void printStudent() const {
        std::cout << firstName << " " << lastName << std::endl;
        address.printAddress();
        std::cout << "DOB: ";
        birthDate.printDate();
        std::cout << "Grad: ";
        gradDate.printDate();
        std::cout << "Credits: " << credits << std::endl;
    }//End printStudent

    std::string getLastFirst() const {
        return lastName + ", " + firstName;
    }//End getLastFirst

    std::string getLastName() const {
        return lastName;
    }//End getLastName

    int getCredits() const {
        return credits;
    }//End getCredits

};//End class Student

std::string menu() {
    std::cout << "\n0) quit\n"
              << "1) print all student names\n"
              << "2) print all student data\n"
              << "3) find a student\n"
              << "Please choose 0-3: ";
    std::string choice;
    std::getline(std::cin, choice);
    return choice;
}//End menu

void loadStudents(const std::string& filename, std::vector<Student*>& students) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }//End if

    std::string line;
    while (std::getline(file, line)) {
        Student* s = new Student();
        s->init(line);
        students.push_back(s);
    }//End while

    file.close();
}//End koadStudents

void showStudentNames(const std::vector<Student*>& students) {
    for (const auto& s : students) {
        std::cout << s->getLastFirst() << std::endl;
    }//End for

}//End showStudentNames

void printStudents(const std::vector<Student*>& students) {
    for (const auto& s : students) {
        s->printStudent();
        std::cout << "____________________________________\n";
    }//End for

}//End printStudent

void findStudent(const std::vector<Student*>& students) {
    std::cout << "Last name of student: ";
    std::string query;
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& s : students) {
        if (s->getLastName().find(query) != std::string::npos) {
            s->printStudent();
            std::cout << "____________________________________\n";
            found = true;
        }//End if

    }//End for

    if (!found) {
        std::cout << "No student found with last name containing: " << query << std::endl;
    }//End if

}//End findStudent

void delStudents(std::vector<Student*>& students) {
    for (auto& s : students) {
        delete s;
    }//End for
    students.clear();
}//End delStudents

int main() {
    std::vector<Student*> students;
    loadStudents("students.csv", students);

    while (true) {
        std::string choice = menu();

        if (choice == "0") {
            break;
        } else if (choice == "1") {
            showStudentNames(students);
        } else if (choice == "2") {
            printStudents(students);
        } else if (choice == "3") {
            findStudent(students);
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }//End if-elif-elif-elif-else

    }//End while

    delStudents(students);
    std::cout << "Goodbye!\n";
    return 0;
}//End main

