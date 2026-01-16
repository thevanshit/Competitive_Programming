#include <iostream>
#include <string>
using namespace std;

class ExampleClass{
    int num;
}; 

struct PersonalInfoStruct{
    string Name;
    int Age;
    void Print_Personal_Info(){
        cout << "Name : " << Name << "\nAge : " << Age << endl;
    }
};

int main (){
    PersonalInfoStruct Person1;
    Person1.Name = "Miles Morals";
    Person1.Age = 16;
    Person1.Print_Personal_Info();
    ExampleClass Person2;
    // Person2.num = 19;
    // cout << Person2.num << endl;
    return 0;
}