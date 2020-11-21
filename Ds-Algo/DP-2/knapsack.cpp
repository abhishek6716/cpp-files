#include<iostream>
using namespace std;


//by DP method
int knapsack_dp(int *wts, int *values, int n, int maxwts){
    int a=n;
    int b=maxwts;
    int **output=new int*[a+1];
    for(int i=0; i<a+1; i++)
    {
        output[i]=new int[b+1];
    }
    for(int j=0; j<b+1; j++)
    {
        output[0][j]=0;
    }
    for(int i=0; i<a+1; i++)
    {
        output[i][0]=0;
    }
    for(int i=1; i<a+1; i++)
    {
        for(int j=1; j<b+1; j++)
        {
            if(wts[i-1]>=j)
            {
                output[i][j]=output[i-1][j];
            }
            int x=output[i-1][j-wts[i-1]]+values[i-1];
            int y=output[i-1][j];
            output[i][j]=max(x, y);
        }
    }
    return output[a][b];
}

/// on second time achived better solution 
/// memoisation
int helper(int *wts, int *val, int n, int maxwts, int **output)
{
    int a=n;
    int b=maxwts;
    if(n==0 || maxwts<=0){
        return 0;
    }
    if(output[a][b]!=-1){
        return output[a][b];
    }
    int ans;
    if(wts[0]>maxwts)
    {
        ans=helper(wts+1, val+1, n-1, maxwts, output);
    }
    else
    {
        int x=helper(wts+1, val+1, n-1, maxwts-wts[0], output)+val[0];
        int y=helper(wts+1, val+1, n-1, maxwts, output);
        ans=max(x, y);
    }
    output[a][b]=ans;
    return ans;
}
int knapsack_mem(int *wts, int *val, int n, int maxwts)
{
    int **output=new int*[n+1];
    for(int i=0; i<n+1; i++){
        output[i]=new int[maxwts+1];
        for(int j=0; j<maxwts+1; j++){
            output[i][j]=-1;
        }
    }
    return helper(wts, val, n, maxwts, output);
}
/*
// first time code written by me having lots of mistakes
int knapsack_mem(int *wts, int *values, int n, int maxwts, int **output){
    int p=n+1;
    int q=maxwts+1;
    //Base case
    if(n==0 || maxwts<=0){
        return 0;
    }
    //check if answer already exists or not
    if(output[p][q]!=-1){
        return output[p][q];
    }
    //Recursive calls
    if(wts[0]>maxwts){
        return knapsack_mem(wts+1, values+1, n-1, maxwts, output);
    }
    int x=knapsack_mem(wts+1, values+1, n-1, maxwts-wts[0], output)+values[0];
    int y=knapsack_mem(wts+1, values+1, n-1, maxwts, output);
    //saving and returning answer
    int ans=max(x, y);
    output[p][q]=ans;
    return ans;
}
int knapsack_mem(int *wts, int *values, int n, int maxwts){
    int p=n+1;
    int q=maxwts+1;
    int **output=new int*[p+1];
    for(int i=0; i<p+1; i++){
        output[i]=new int[q+1];
        for(int j=0; j<q+1; j++){
            output[i][j]=-1;
        }
    }
    return knapsack_mem(wts, values, n, maxwts, output);
}
*/




//Brute force method
int knapsack(int *wts, int *values, int n, int maxwts){
    if(n==0 || maxwts<=0){
        return 0;
    }
    if(wts[0]>maxwts){
        return knapsack(wts+1, values+1, n-1, maxwts);
    }
    int x=knapsack(wts+1, values+1, n-1, maxwts-wts[0])+values[0];
    int y=knapsack(wts+1, values+1, n-1, maxwts);
    return max(x, y);
}



int main() {
	int n; 
    cout<<"enter no of items ";
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];
    cout<<"enter their weights ";
	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}
    cout<<"enter their respective values ";
	for(int i = 0; i < n; i++){
		cin >> values[i];
	}
	int maxWeight;
    cout<<"enter maxWt ";
	cin >> maxWeight;
	cout << knapsack(weights, values, n, maxWeight) << endl;
    cout<<knapsack_mem(weights, values, n, maxWeight)<<endl;
    cout<<knapsack_dp(weights, values, n, maxWeight)<<endl;
}




