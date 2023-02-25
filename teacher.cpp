#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
};

class Student : virtual public Person {
	
private:
	
    float percentage;
public: 

    Student(string n, int a) : Person(n, a), percentage(0) {}
      void inputdata() {
          cout << "Enter percentage: ";
          cin >> percentage;
    }
    void displaydata() {
         cout << "Name: " << name << endl;
          cout << "Age: " << age << endl;
           cout << "Percentage: " << percentage << "%" << endl;
    }
};

class Teacher : virtual public Person {
private:
    int salary;
public:
    Teacher(string n, int a) : Person(n, a), salary(0) {}
    void inputdata() {
        cout << "Enter salary: ";
        cin >> salary;
    }
    void displaydata() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Faculty : public Student, public Teacher {
public:
    Faculty(string n, int a) : Person(n, a), Student(n, a), Teacher(n, a) {}
};

int main() {
    Faculty faculty("dear", 45);
    faculty.Student::inputdata();
    faculty.Teacher::inputdata();
    faculty.Student::displaydata();
    faculty.Teacher::displaydata();
    return 0;
}