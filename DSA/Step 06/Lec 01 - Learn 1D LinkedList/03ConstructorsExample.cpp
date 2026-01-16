#include <iostream>
#include <string>
using namespace std;

class PersonalInfo{
    public : 
    string name = "Spider-Man";
    int age = 19;

    void Print_Personal_Info_Default(){
        cout << "Name : " << name << "\nAge : " << age << endl;
    }
    void Print_Personal_Info_Parameterized(string Name, int Age){
        cout << "Name : " << Name << "\nAge : " << Age << endl;
    }
};
int main (){
    PersonalInfo Person1;
    Person1.Print_Personal_Info_Default();
    Person1.Print_Personal_Info_Parameterized("Peter Parker", 19);
    return 0;
}