# CS121Lab7

## Algorithm

> include iostream, string, sstream, vector, string

> class Address:

> > private contains a string called street, city, state, and zip

> > public:

> > > void init const of of string& st, c, s, and z:

> > > > make private Address strings equal their abbreviated version using string&

> > > void printAddress const:
> > > > print address info

> class Date:

> > private cotains a string called dateStr

> > public:

> > > void init cost string& ds:
> > > > dateSTR contains ds

> > > void printDate const:
> > > > print dateSTR

> class Student:

> > private:
> > > 2 strings called firstName and lastName
> > > Address variable called address
> > > Date variables called birthDate andgradDate
> > > int called credits

> > public:

> > > void init const string& data:
> > > > getline ss for firstName, lastName, street, city, state, zip, birth, grad

> > > > create string creditSTR and getline ss for that created string
> > > > makes credits cotain stoi creditStr

> > > > address init cotains street, city, state, and zip
> > > > birthDate init contains birth
> > > > gradDate init grad

> > > void printStudent const:

> > > > print firstName and LastName

> > > > print Birth Date
> > > > birthDate printDate

> > > > print Graduation Date
> > > > gradDate printDate

> > > > print credits

> > > string getLastFirst const:
> > > > return lastName and firstName

> > > string getLastName const {
> > > > return lastName and firstname

> > > string getLastName const
> > > > return lastName

> > > int getCredits const
> > > > return credits

> string menu
> >  give user the options

> void loadStudent
> > if file not true
> > > print failed to open filename

> > while getLine
> > > new student
> > > s poinrs to init
> > > student push back on s

> void showStudentNames
> > for const auto s : students
> > s pints to printStudent

> void findStudent
> > print Last name of students
> > for const auto s : students
> > > if s points to getLastname as it finds query and not equal to string npos
> > > > s points to printStudent and found true
> > if not found
> > > print no students with that last name

> void delStudents
> > for auto s : students
> > > delete s



> int main
> > if choice 0
> > > break
> > elif 1
> > > showStudentNames
> > elif 2
> > > printStudents
> > elif 3
> > > findStudent
> > else
> > > print invalid choice

> > delStudents then print goodbye and return 0
## UML Diagram

```mermaid 
classDiagram
    class Date{
        - string dateStr
        - int month
        - int day
        - int year
        + Date()
        + void init(dateStr)
        + void printDate()
    }
    class Address{
      - string street
      - string city
      - string state
      - string zip
      + Address()
      + void init(street, city, state, zip)
      + void printAddress()
    }
    class Student{
      - string studentString
      - string firstName
      - Hstring lastName
      - Date* dob
      - Date* grad
      - Address* Address
      - int credits
      + Student()
      + void init(studentString)
      + void printStudent()
      + string firstName()
      + string lastName()
      + int creditHours()
    }
    Student --> Address
    Student --> Date
