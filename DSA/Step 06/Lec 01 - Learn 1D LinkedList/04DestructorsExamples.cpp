#include <iostream>
#include <string>
using namespace std;

class PersonalInfo{
    public : 
    PersonalInfo(){
        cout << "Constructor" << endl;
    }
    ~PersonalInfo(){
        cout << "Desstructor" << endl;
    }
};
int main (){
    PersonalInfo Person1;
    PersonalInfo Person2;
    PersonalInfo Person3;
    return 0;
}