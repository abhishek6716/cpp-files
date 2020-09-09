#include<iostream>
using namespace std;

int charlength(char a[]){
    int cnt=0;
    for(int i=0; a[i]!='\0'; i++){
        cnt++;
    }
    return cnt;
}
void reverse(char input[], int start, int end){
    int i=start, j=end;
    while(i<j){
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}
void reverseStringWordWise(char input[]){
    int previousSpaceIndex=-1;
    int i=0;
    for(; input[i]!='\0'; i++){
        if(input[i]==' '){
            reverse(input, previousSpaceIndex+1, i-1);
            previousSpaceIndex=i;
        }
    }
    reverse(input, previousSpaceIndex+1, i-1);
    reverse(input, 0, i-1);
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}