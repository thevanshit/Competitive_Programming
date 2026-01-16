#include <iostream>
#include <string>
using namespace std;

class PersonalInfo{
    public : 
    string name = "Spider-Man";
    int age = 19;

    void Print_Personal_Info_Outside_Class();
    void Print_Personal_Info_Inside_Class(){
        cout << "Name : " << name << "\nAge : " << age << endl;
    }
};
void PersonalInfo :: Print_Personal_Info_Outside_Class(){
    cout << "Name : " << name << "\nAge : " << age << endl;
}
int main (){
    PersonalInfo Person1;
    Person1.name = "Peter Parker";
    Person1.age = 19;
    Person1.Print_Personal_Info_Inside_Class();
    Person1.Print_Personal_Info_Outside_Class();
    return 0;
}