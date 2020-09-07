#include<iostream>
#include<string>
using namespace std;



int editDist_dp(string s, string t){
    int m=s.size();
    int n=t.size();
    int **output=new int*[m+1];
    for(int i=0; i<m+1; i++){
        output[i]=new int[n+1];
    }
    //fill first row
    for(int j=0; j<n+1; j++){
        output[0][j]=j;
    }
    //fill first column
    for(int i=0; i<m+1; i++){
        output[i][0]=i;
    }
    //fill other cells
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[m-i]==t[n-j]){
                output[i][j]=output[i-1][j-1];
            }
            else{
                int a=output[i-1][j]+1;
                int b=output[i][j-1]+1;
                int c=output[i-1][j-1]+1;
                output[i][j]=min(a, min(b, c));
            }
        }
    }
    return output[m][n];
}




int editDist_mem(string s, string t, int **output){
    int m=s.size();
    int n=t.size();
    //base case
    if(s.size()==0 || t.size()==0){
        return max(s.size(), t.size());
    }
    //check if answer already exists or not
    if(output[m][n]!=-1){
        return output[m][n];
    }
    //recursive calls
    int ans;
    if(s[0]==t[0]){
        ans=editDist_mem(s.substr(1), t.substr(1), output);
    }
    else{
        //insert 
        int x=editDist_mem(s.substr(1), t, output)+1;
        //delete
        int y=editDist_mem(s, t.substr(1), output)+1;
        //update
        int z=editDist_mem(s.substr(1), t.substr(1), output)+1;
        ans=min(x, min(y, z));
    }
    //save calculation
    output[m][n]=ans;
    //return answer
    return ans;
}
int editDist_mem(string s, string t){
    int m=s.size();
    int n=t.size();
    int **output=new int*[m+1];
    for(int i=0; i<m+1; i++){
        output[i]=new int[n+1];
        for(int j=0; j<n+1; j++){
            output[i][j]=-1;
        }
    }
    return editDist_mem(s, t, output);
}




int editDist(string s, string t){
    if(s.size()==0 || t.size()==0){
        return max(s.size(), t.size());
    }
    if(s[0]==t[0]){
        return editDist(s.substr(1), t.substr(1));
    }
    else{
        //insert 
        int x=editDist(s.substr(1), t)+1;
        //delete
        int y=editDist(s, t.substr(1))+1;
        //update
        int z=editDist(s.substr(1), t.substr(1))+1;
        return min(x, min(y, z));
    }
}



int main(){
    string s, t;
    cout<<"enter two strings ";
    cin>>s>>t;
    cout<<editDist(s, t)<<endl;
    cout<<editDist_mem(s, t)<<endl;
    cout<<editDist_dp(s, t)<<endl;
}