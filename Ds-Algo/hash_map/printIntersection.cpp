#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int printIntersection(int input1[], int input2[], int n1, int n2){
    sort(input1, input1+n1);
    sort(input2, input2+n2);
    int i=0; 
    int j=0;
    while(i<n1 && j<n2){
        if(input1[i]==input2[j]){
            cout<<input1[i]<<" ";
            i++;
            j++;
        }
        else if(input1[i]<input2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}