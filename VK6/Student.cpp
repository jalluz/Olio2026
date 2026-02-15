#include "Student.h"

Student::Student(string name, int age)
{
    Name = name;
    Age = age;
}

void Student::setName(string name)
{
    Name = name;
}

void Student::setAge(int age)
{
    Age = age;
}

string Student::getName()
{
    return Name;
}

int Student::getAge()
{
    return Age;
}

void Student::printStudentInfo()
{
    cout << "Name: " << Name << ", Age: " << Age << endl;
}
