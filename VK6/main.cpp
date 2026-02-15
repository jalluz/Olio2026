#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

int main()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
        {
            string name;
            int age;

            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;

            Student s(name, age);
            studentList.push_back(s);
            break;
        }

        case 1:
        {
            for (auto& s : studentList)
            {
                s.printStudentInfo();
            }
            break;
        }

        case 2:
        {
            sort(studentList.begin(), studentList.end(),
                 [](Student& a, Student& b)
                 {
                     return a.getName() < b.getName();
                 });

            for (auto& s : studentList)
            {
                s.printStudentInfo();
            }
            break;
        }

        case 3:
        {
            sort(studentList.begin(), studentList.end(),
                 [](Student& a, Student& b)
                 {
                     return a.getAge() < b.getAge();
                 });

            for (auto& s : studentList)
            {
                s.printStudentInfo();
            }
            break;
        }

        case 4:
        {
            string searchName;
            cout << "Enter name to find: ";
            cin >> searchName;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [&](Student& s)
                              {
                                  return s.getName() == searchName;
                              });

            if (it != studentList.end())
            {
                it->printStudentInfo();
            }
            else
            {
                cout << "Student not found" << endl;
            }
            break;
        }
        }

    } while(selection < 5);

    return 0;
}
