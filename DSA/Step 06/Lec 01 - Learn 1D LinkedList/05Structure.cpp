#include <iostream>
#include <string>
using namespace std;

struct PersonalInfo{
    string Name;
    int Age;
    void Print_Personal_Info(){
        cout << "Name : " << Name << "\nAge : " << Age << endl;
    }
};
int main (){
    PersonalInfo Person1;
    Person1.Name = "Miles Morals";
    Person1.Age = 16;
    Person1.Print_Personal_Info();
    return 0;
}