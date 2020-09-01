#include<iostream>
#include<string>
using namespace std;

bool findWinner(int x, int y, int n) 
{ 
    int dp[n + 1]; 
    dp[0] = false; 
    dp[1] = true; 
    for (int i = 2; i <= n; i++) { 
        if (i - 1 >= 0 and !dp[i - 1]) 
            dp[i] = true; 
        else if (i - x >= 0 and !dp[i - x]) 
            dp[i] = true; 
        else if (i - y >= 0 and !dp[i - y]) 
            dp[i] = true; 
        else
            dp[i] = false; 
    } 
    return dp[n]; 
} 

int main() 
{ 
    int x, y, n;
    cin>>x>>y>>n; 
    if (findWinner(x, y, n)) 
        cout <<"Whis"; 
    else
        cout <<"Beerus"; 
}