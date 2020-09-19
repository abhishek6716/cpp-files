#include<iostream>
using namespace std;

class fraction{
    
    private:
    int numerator;
    int denominator;
    
    public:
    fraction(int numerator, int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }

    void print(){
        cout<<this->numerator<<"/"<<this->denominator<<endl;
    }

    void simplify(){
        int gcd=1;
        int j=min(this->numerator, this->denominator);
        for(int i=1; i<=j; i++){
            if(this->numerator%i==0 && this->denominator%i==0){
                gcd=i;
            }
        }
        this->numerator=this->numerator/gcd;
        this->denominator=this->denominator/gcd;
    }

    fraction add(fraction const &f2){
        int lcm=this->denominator*f2.denominator;
        int x=lcm/this->denominator;
        int y=lcm/f2.denominator;

        int num=(x*this->numerator)+(y*f2.numerator);
        //this->numerator=num;
        //this->denominator=lcm;
        fraction newFraction(num, lcm);
        newFraction.simplify();
        return newFraction;
    }

    fraction operator+(fraction const &f2) const {                                             // operator+ overloading
        int lcm=this->denominator*f2.denominator;
        int x=lcm/this->denominator;
        int y=lcm/f2.denominator;

        int num=(x*this->numerator)+(y*f2.numerator);
        //this->numerator=num;
        //this->denominator=lcm;
        fraction newFraction(num, lcm);
        newFraction.simplify();
        return newFraction;
    }

    void multiply(fraction const &f2){
        this->numerator=this->numerator*f2.numerator;
        this->denominator=this->denominator*f2.denominator;
        simplify();
    }

    fraction operator*(fraction const &f2) const {                                             // operator* overloading
        int num=this->numerator*f2.numerator;
        int den=this->denominator*f2.denominator;
        fraction newFraction(num, den);
        newFraction.simplify();
        return newFraction;
    }

    bool operator==(fraction const &f2) const {                                                // operator== overloading
        return (this->numerator==f2.numerator && this->denominator==f2.denominator);
    }

    fraction& operator++(){                                                                    // Pre-Increment
        this->numerator=this->numerator+denominator;
        simplify();
        return *this;
    }

    fraction operator++(int){                                                                  // Post-Increment
        fraction fNew(this->numerator, this->denominator);
        this->numerator=this->numerator+this->denominator;                                     // Post-Increment nesting not allowed (i++)++
        simplify();
        fNew.simplify();
        return fNew;
    }

    fraction& operator+=(fraction const &f2){                                                  // Operator+=
        int lcm=this->denominator*f2.denominator;                                              // nesting is allowed
        int x=lcm/this->denominator;
        int y=lcm/f2.denominator;
        int num=(x*this->numerator)+(y*f2.numerator);
        this->numerator=num;
        this->denominator=lcm;
        simplify();
        return *this;
    }

};

int main(){
    fraction f1(2,3);
    fraction f2(1,2);
    fraction f3=f1.add(f2);
    fraction f4=f1+f2;
    f1.print();
    f2.print();
    f3.print();
    f4.print();
    fraction f5=f1*f2;
    f5.print();
    fraction f6=++(++f5);
    f5.print();
    f6.print();
}