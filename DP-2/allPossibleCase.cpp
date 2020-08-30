#include <iostream>
#include<cmath>
using namespace std;

int helper(int x, int n, int num) 
{ 
    int val = (x - pow(num, n)); 
    if (val == 0){
        return 1;
    } 
    if (val < 0){
        return 0;
    } 
    // Consider two possibilities, num is 
    // included and num is not included. 
    int x=helper(val, n, num + 1);
    int y=helper(x, n, num + 1); 
    return (x+y); 
} 
int allWays(int x, int n) 
{ 
    return helper(x, n, 1); 
}  

int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}
