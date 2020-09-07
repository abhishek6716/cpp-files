#include <iostream>
using namespace std;


int getMaxMoney_dp(int arr[], int n){
    int *output=new int[n+1];
    output[0]=arr[0];
    output[1]=max(arr[1], output[0]);
    for(int i=2; i<n+1; i++){
        output[i]=max(arr[i]+output[i-2], output[i-1]);
    }
    return output[n];
}



int getMaxMoney_mem(int arr[], int n, int *output){
    if(n<=0){
        return 0;
    }
    if(output[n]!=-1){
        return output[n];
    }
    int x=arr[0]+getMaxMoney_mem(arr+2, n-2, output);
    int y=getMaxMoney_mem(arr+1, n-1, output);
    output[n]=max(x, y);
    return output[n];

}
int getMaxMoney_mem(int arr[], int n){
    int *output=new int[n+1];
    for(int i=0; i<n+1; i++){
        output[i]=-1;
    }
    return getMaxMoney_mem(arr, n, output);
}


int getMaxMoney(int arr[], int n){
    if(n<=0){
        return 0;
    }
    //If current house is selected
    int x=arr[0]+getMaxMoney(arr+2, n-2);
    //If current house is not selected
    int y=getMaxMoney(arr+1, n-1);
    return max(x, y);
}

int main(){
    int n;
    cout<<"enter no of houses ";
    cin >> n;
    cout<<"enter money in their respective house ";
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n)<<endl;
    cout<<getMaxMoney_mem(arr, n)<<endl;
    cout<<getMaxMoney_dp(arr, n);
}