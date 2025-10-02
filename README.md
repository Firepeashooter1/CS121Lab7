# CS121Lab7

## UML Diagram

```mermaid 
classDiagram
    Student <|-- Address
    Student <|-- Date
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

## Algorithm

> include iostream, string, sstream

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
> > > > address printAddress

> > > > print Birth Date
> > > > birthDate printDate

> > > > print Graduation Date
> > > > gradDate printDate

> > > > print credits

> > > string getLastFirst const:
> > > > return lastName and firstName

> void testDate:
> > Date d
> > d init and then printDate

> void testStudent:
> > have a string called studentString with all the info

> > Student* student equals a new Student

> > student points to a printStudent that comes on the line after a init containing a studentString

> > student pointing to getLastFirst

> > delete student

> int main:

> > print hello

> >  do testAdress, testDate, and testStudent in that order

> > return 0
