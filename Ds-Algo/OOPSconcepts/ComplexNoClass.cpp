#include<iostream>
using namespace std;

class ComplexNo{

    private:
    int real;
    int imaginary;

    public:
    ComplexNo(int real, int imaginary){
        this->real=real;
        this->imaginary=imaginary;
    }

    void print(){
        if(this->imaginary>=0){
            cout<<this->real<<"+"<<this->imaginary<<"i"<<endl;
        } else{
            cout<<this->real<<this->imaginary<<"i"<<endl;
        }
    }

    void Plus(ComplexNo const &c2){
        this->real=this->real+c2.real;
        this->imaginary=this->imaginary+c2.imaginary;
    }

    void Multiply(ComplexNo const &c2){
        int x=(this->real)*(c2.real)-(this->imaginary)*(c2.imaginary);
        int y=(this->real)*(c2.imaginary)+(this->imaginary)*(c2.real);
        this->real=x;
        this->imaginary=y;  
    }
};
int main(){
    ComplexNo c1(-2, 3);
    ComplexNo c2(5, -10);
    c1.print();
    c2.print();
    c1.Plus(c2);
    c1.print();
    c2.print();
    c1.Multiply(c2);
    c1.print();
}