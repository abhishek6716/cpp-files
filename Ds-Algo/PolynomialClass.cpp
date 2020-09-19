#include<iostream>
using namespace std;

//Default constructor
//copy constructor
//copy assignment operator
//print
//set coefficient
//operator+
//operator-
//operator*
class Polynomial{
    private:
    int *degCoeff;
    int capacity;

    public:
    Polynomial(){                                                                   //Default constructor
        capacity=5;
        degCoeff=new int[5];
        for(int i=0; i<capacity; i++){
            degCoeff[i]=0;
        }
    }

    Polynomial(Polynomial const &p){                                                //copy constructor
        this->degCoeff=new int[p.capacity];
        for(int i=0; i<p.capacity; i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
        this->capacity=p.capacity;
    }

    int getCoeff(int degree){                                                       //getter
        if(degree>=capacity){
        return 0;
        }
        return degCoeff[degree];
    }

    void setCoeff(int degree, int coeff){                                           //setter
        if(degree>=capacity){
            int size=2*capacity;
            while(size<=degree){
                size=size*2;
            }
            int *newDegCoeff=new int[size];
            for(int i=0; i<size; i++){
                newDegCoeff[i]=degCoeff[i];
            }
            capacity=size;
            delete[] degCoeff;
            degCoeff=newDegCoeff;
        }
        degCoeff[degree]=coeff;
    }

    void print(){                                                                   //print
        for(int i=0; i<capacity; i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }

    Polynomial operator+(Polynomial const &p){                                      //operator+
        Polynomial pNew;
        int i=0, j=0;
        while(i<this->capacity && j<p.capacity){
            int deg=i;
            int coeff=this->degCoeff[i]+p.degCoeff[j];
            pNew.setCoeff(deg, coeff);
            i++;
            j++;
        }
        while(i<capacity){
            pNew.setCoeff(i, degCoeff[i]);
            i++;
        }
        while(j<p.capacity){
            pNew.setCoeff(j, p.degCoeff[j]);
            j++;
        }
        return pNew;
    }

    Polynomial operator-(Polynomial const p){                                       //operator-
        Polynomial pNew;
        int i=0, j=0;
        while(i<this->capacity && j<p.capacity){
            int deg=i;
            int coeff=this->degCoeff[i]-p.degCoeff[j];
            pNew.setCoeff(deg, coeff);
            i++;
            j++;
        }
        while(i<capacity){
            pNew.setCoeff(i, degCoeff[i]);
            i++;
        }
        while(j<p.capacity){
            pNew.setCoeff(j, (-1*p.degCoeff[j]));
            j++;
        }
        return pNew;
    }

    void operator=(Polynomial const &p){                                            //operator=                                  
        delete[] degCoeff;
        degCoeff=new int [p.capacity];
        for(int i=0; i<p.capacity; i++){
            degCoeff[i]=p.degCoeff[i];
        }
        capacity=p.capacity;
    }

    Polynomial operator*(Polynomial p){                                             //operator*
        Polynomial pNew;
        for(int j=0; j<p.capacity; j++){
            for(int i=0; i<capacity; i++){
                int deg=i+j;
                int coeff=pNew.getCoeff(deg)+(this->degCoeff[i]*p.degCoeff[j]);
                pNew.setCoeff(deg, coeff);
            }
        }
        return pNew;
    }
};

