#include<iostream>
#include<cstring>
using namespace std;

class Student{   
    private:
    int age;

    public:
    char *name;

    Student(int age, char *name){
        this->age=age;
        //shallow copy
        //this->name=name;
        //deep copy
        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
    }

    void display(){
        cout<<age<<" "<<name<<endl;
    }

    //copy constructor
    Student(Student const &s){
        this->age=s.age;
        //this->name=s.name;                             // shallow copy
        this->name=new char[strlen(s.name)+1];           // deep copy
        strcpy(this->name, s.name);
    }
};
int main(){
    char name[]="abcd";
    Student s1(20, name);
    s1.display();
    /*
    name[3]='e';
    Student s2(24, name);
    s2.display();
    s1.display();
    */
   Student s2(s1);
   s2.name[0]='x';
   s1.display();
   s2.display();
}