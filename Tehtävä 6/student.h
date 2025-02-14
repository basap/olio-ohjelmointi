#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student
{
public:
    Student(string name, int age);
    void setAge(int age);
    void setName(string name);
    string getName();
    int getAge();
    void printStudentInfo();

private:
    string Name;
    int Age;
};

#endif // STUDENT_H
