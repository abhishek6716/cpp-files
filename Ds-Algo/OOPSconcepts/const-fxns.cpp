#include<iostream>
using namespace std;

class fraction{
    
    private:
    int numerator;
    int denominator;
    
    public:
    fraction(){

    }
    fraction(int numerator, int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }

    int getNumerator() const {
        return numerator;
    }
    int getDenominator() const {
        return denominator;
    }
    void setNumerator(int n){
        this->numerator=n;
    }
    void setDenominator(int d){
        this->denominator=d;
    }

    void print() const {
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

    void add(fraction const &f2){
        int lcm=this->denominator*f2.denominator;
        int x=lcm/this->denominator;
        int y=lcm/f2.denominator;

        int num=(x*this->numerator)+(y*f2.numerator);
        this->numerator=num;
        this->denominator=lcm;
        simplify();
    }

    void multiply(fraction const &f2){
        this->numerator=this->numerator*f2.numerator;
        this->denominator=this->denominator*f2.denominator;
        simplify();
    }
};

int main(){
    fraction f1(10,2);
    fraction f2(15, 2);

    fraction const f3;
    cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl;
    //f3.setNumerator(10);                                     //not allowed change
}