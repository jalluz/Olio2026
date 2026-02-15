#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student
{
private:
    string Name;
    int Age;

public:
    Student(string name, int age);

    void setName(string name);
    void setAge(int age);

    string getName();
    int getAge();

    void printStudentInfo();
};

#endif
