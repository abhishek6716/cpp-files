#include<iostream>
using namespace std;

int mcm_mem(int p[], int i, int j, int **output){
    if (i >= j){
        return 0; 
    }
    if(output[i][j]!=-1){
        return output[i][j];
    }
    int k; 
    int min = INT_MAX; 
    for (k = i; k < j; k++) { 
        int temp = mcm_mem(p, i, k, output) + mcm_mem(p, k + 1, j, output) + (p[i - 1] * p[k] * p[j]); 
        if (temp < min){
            min = temp; 
        }
    } 
    output[i][j]=min;
    return min; 
}
int mcm_mem(int p[], int m){
    int arrsize=m+1;
    int **output=new int*[arrsize];
    for(int i=0; i<arrsize; i++){
        output[i]=new int[arrsize];
        for(int j=0; j<arrsize; j++){
            output[i][j]=-1;
        }
    }
    return mcm_mem(p, 1, arrsize-1, output); 
}

int mcm(int p[], int i, int j) 
{ 
    if (i >= j){
        return 0; 
    }
    int k; 
    int min = INT_MAX; 
    for (k = i; k < j; k++) { 
        int temp = mcm(p, i, k) + mcm(p, k + 1, j) + (p[i - 1] * p[k] * p[j]); 
        if (temp < min){
            min = temp; 
        }
    } 
    return min; 
} 
int mcm(int p[], int m){
    int arrsize=m+1;
    return mcm(p, 1, arrsize-1);
}

int main(){

  int m; 
  cout<<"enter no of matrices ";
  cin >> m;
  int* p = new int[m];
  cout<<"enter elements of array ";
  for(int i = 0; i <= m; i++){
    cin >> p[i];
  }

  cout << mcm(p, m)<<endl;
  cout<<mcm_mem(p, m);

}
