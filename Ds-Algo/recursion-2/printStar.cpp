#include<iostream>
#include<cstring>
using namespace std;

int length(char input[]){
    int len=0;
    for(int i=0; input[i]!='\0'; i++){
        len++;
    }
    return len;
}
void helper(char input[], int start)
{
    if(input[start]=='\0'){
		return;
	}
    helper(input, start+1);
    if(input[start] == input[start+1]){
        int l = strlen(input);
		input[l+1] = '\0';
		int i;
		for(i = l-1; i>=start+1 ;i--){
			input[i+1] = input[i];
		}
		input[start+1] = '*';
    }
}
void pairStar(char input[]) {
   helper(input, 0);
}