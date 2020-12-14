/////////// fibo ///////////////
/*
int fib(int n){
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
*/


/////////// climbing stairs ///////////////
/*
int cs(int n){
    int dp[n + 1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        if(i >= 2){
            dp[i] += dp[i - 2];
        }
        if(i >= 3){
            dp[i] += dp[i - 3];
        }
    }
    return dp[n];

}
int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}
*/


////////// Climb Stairs With Variable Jumps //////////
/*
int cs(int arr[], int n){
    int dp[n + 1];
    for(int i = 0 ; i <= n; i++){
        dp[i] = 0;
    }
    dp[n] = 1;

    for(int i = n - 1; i >= 0; i--){
        for(int jumps = 1; jumps <= arr[i]; jumps++){
            if(i + jumps <= n){
                dp[i] += dp[i + jumps];
            }
        }
    }
    return dp[0];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}
*/