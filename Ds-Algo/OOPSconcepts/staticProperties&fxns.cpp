#include<iostream>
using namespace std;

class student{
    private:
    static int totalStudents;                 // total no of students present

    public:
    int rollNo;
    int age;

    student(){
        totalStudents++;
    }

    int getRollNo(){
        return rollNo;
    }

    static int getTotalStudents(){              // static function uses only static properties or static fxns
        return totalStudents;
    }
};
int student::totalStudents=0;                 //initialize static data members

int main(){
    student s1;
    student s2;
    student s3, s4, s5;
    cout<<student::getTotalStudents()<<endl; 
}