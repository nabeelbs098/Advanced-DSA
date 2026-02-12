#include <iostream>
#include <string>
using namespace std;
class Student
{public:
    int id;
    string name;
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};
int main()
{
    Student s1;
    s1.id = 1;
    s1.name = "Nabeel";
    s1.display();

    Student* ptr = &s1;
    cout << "Using pointer to access members:" << endl;
    cout << "ID: " << ptr->id << endl;
    cout << "Name: " << ptr->name << endl;

    return 0;
}