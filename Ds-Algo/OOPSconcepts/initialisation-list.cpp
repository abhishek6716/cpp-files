#include<iostream>
using namespace std;

class student{
    public:
    int age;
    const int rollNo;
    int &x;                     // age reference variable

    student(int r, int age) : rollNo(r), age(age), x(this->age){
        // rollNo=r;
    }
};

int main(){
    student s1(101, 20);
    s1.age=20;
}