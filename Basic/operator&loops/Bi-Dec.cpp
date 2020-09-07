#include<iostream>
#include<cmath>
using namespace std;
 
 int main(){
     int bin; cin>>bin;
     int no=0, rem, i=0;
     while(bin){
         rem=bin%10;
         no=no*pow(2, i)+rem;
         bin=bin/10;
         i++;
     }
     cout<<no;
 }