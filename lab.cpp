#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

template <class T>
class Student
{
private:
    T rollNo;

public:
    string name;
    int age;
    Student(T x)
    {
        rollNo = x;
    }
    T getRollNo()
    {
        return rollNo;
    }

    void getStudentInfo()
    {
        string str;
        int a;
        cout << "Enter Name: " << endl;
        cin >> str;
        name = str;
        cout << "Enter Age: " << endl;
        cin >> a;
        age = a;
    }
    void display()
    {

        cout << "Name of Student:  " << name << endl;
        cout << "Age of Student: " << age << endl;
        cout << "Student Roll Number: " << rollNo << endl;
    }
};

void swap(Student<int> &a, Student<int> &b)
{
    Student<int> temp = a;
    a = b;
    b = temp;
}

int main()
{

    int n;
    cout << "Enter Number of Students: " << endl;
    cin >> n;

    vector<Student<int>> stud;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter details of Student number " << (i + 1) << endl;
        int rollNo;
        cout << "Student Roll Number: " << endl;
        cin >> rollNo;
        stud.push_back(Student<int>(rollNo));
        stud[i].getStudentInfo();
    }
    cout << "\n\n";

    cout << "Initial List of Students " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Details of Student number " << (i + 1) << endl;
        stud[i].display();
        cout << "\n";
    }
    cout << "\n\n";
    cout << "swapping alternate Student " << endl;

    for (int i = 0; i < n - 2; i++)
    {
        swap(stud[i], stud[i + 2]);
    }
    cout << "Details of students after Swapping" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Details of Student number" << (i + 1) << endl;
        stud[i].display();
        cout << "\n";
    }
}