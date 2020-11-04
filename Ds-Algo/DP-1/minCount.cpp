#include<iostream>
#include<cmath>
using namespace std;

int minCount_2(int n)                                           //By DP
{ 
    int *ans = new int[n + 1];  
    ans[0] = 0; 
    ans[1] = 1; 
    ans[2] = 2; 
    ans[3] = 3;  
    for (int i = 4; i <= n; i++) { 
        ans[i] = i;  
        for (int j = 1; j <= ceil(sqrt(i)); j++) {  
            if ((j*j)>i) 
                break; 
            else
                ans[i]=min(ans[i], 1 + ans[i-(j*j)]); 
        } 
    } 
    int res = ans[n]; 
    delete[] ans; 
    return res; 
} 

int minCount_1(int n){
    if(sqrt(n)-floor(sqrt(n))==0){                              //Base case-1
        return 1;
    }
    if(n<=3){                                                    //Base case-2
        return n;
    }

    int ans=n;
    for(int i=1; i<=n; i++){
        if((i*i)>n){
            break;
        } else{
            ans=min(ans, 1+minCount_1(n-(i*i)));
        }
    }
    return ans;
}

int main(){
    cout<<"enter a no ";
    int n; cin>>n;
    cout<<minCount_1(n)<<endl;
    cout<<minCount_2(n)<<endl;
}