#include<iostream>
#include<cmath>
using namespace std;

double geometricSum(int k){
    if(k==0){
        return 1;
    }
    double ans=geometricSum(k-1);
    double a=1/(pow(2, k));
    return ans+a;
}
int main(){
    int k; cin>>k;
    cout<<geometricSum(k)<<endl;
}