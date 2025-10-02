#include <iostream>
#include <string>
#include <sstream>

class Address {
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

public:

    void init(const std::string& st, const std::string& c, const std::string& s, const std::string& z) {
        street = st;
        city = c;
        state = s;
        zip = z;
    }//end void int const std string& st, c, s, and z

    void printAddress() const {
        std::cout << street << "\n" << city << ", " << state << " " << zip << std::endl;
    }//end void printAddress const

};//end Address

class Date {
private:
    std::string dateStr;

public:

    void init(const std::string& ds) {
        dateStr = ds;
    }//end void init const std string& ds

    void printDate() const {
        std::cout << dateStr << std::endl;
    }//end void printDate const

};//end class Date

class Student {
private:
    std::string firstName;
    std::string lastName;
    Address address;
    Date birthDate;
    Date gradDate;
    int credits;

public:

    void init(const std::string& data) {
        std::stringstream ss(data);
        std::string street, city, state, zip, birth, grad;

        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, street, ',');
        std::getline(ss, city, ',');
        std::getline(ss, state, ',');
        std::getline(ss, zip, ',');
        std::getline(ss, birth, ',');
        std::getline(ss, grad, ',');
        std::string creditStr;
        std::getline(ss, creditStr);
        credits = std::stoi(creditStr);

        address.init(street, city, state, zip);
        birthDate.init(birth);
        gradDate.init(grad);
    }//end void init const std string& data

    void printStudent() const {
        std::cout << firstName << " " << lastName << std::endl;
        address.printAddress();
        std::cout << "Birth Date: ";
        birthDate.printDate();
        std::cout << "Graduation Date: ";
        gradDate.printDate();
        std::cout << "Credits: " << credits << std::endl;
    }//end printStudent const

    std::string getLastFirst() const {
        return lastName + ", " + firstName;
    }//end std string getLastFirst const

};//end Student

void testAddress() {
    Address a;
    a.init("123 W Main St", "Muncie", "IN", "47303");
    a.printAddress();
}//end testAddress

void testDate() {
    Date d;
    d.init("01/27/1997");
    d.printDate();
}//end testDate

void testStudent() {
    std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
    Student* student = new Student();
    student->init(studentString);
    student->printStudent();
    std::cout << std::endl;
    std::cout << student->getLastFirst() << std::endl;
    delete student;
}//end testStudent

int main() {
    std::cout << "Hello!" << std::endl;
    testAddress();
    testDate();
    testStudent();
    return 0;
}//end main
