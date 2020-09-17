#include<iostream>
#include<algorithm>
using namespace std;

// time complexity o(mlogm+nlogn)

void ArrayIntersection(int input1[], int input2[], int size1, int size2){
    sort(input1, input1+size1);
    sort(input2, input2+size2);

    int i=0, j=0;
    while(i<size1 && j<size2){
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
int main(){
    int arr1[100];
    int n1; cin>>n1;
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }
    int arr2[100];
    int n2; cin>>n2;
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }
    cout<<endl;
    ArrayIntersection(arr1, arr2, n1, n2);
}