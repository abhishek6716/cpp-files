#include<iostream>
#include<algorithm>
using namespace std;

void TripletSum(int input[], int size, int x){
    
    sort(input, input+size);
    
    for(int i=0; i<size; i++){
        int start=i+1;
        int end=size-1;
        int val=x-input[i];
        while(start<end){
            if(input[start]+input[end]>val){
                end--;
            }
            else if(input[start]+input[end]<val){
                start++;
            }
            else{
                int count1=0, count2=0;
                for(int ptr=start; ptr<=end; ptr++){
                    if(input[ptr]==input[start]){
                        count1++;
                    }
                    else{
                        break;
                    }
                }
                for(int ptr=end; ptr>=start; ptr--){
                    if(input[ptr]==input[end]){
                        count2++;
                    }
                    else{
                        break;
                    }
                }
                int combinations=count1*count2;
                if(input[start]==input[end]){
                    combinations=((end-start+1)*(end-start))/2;
                }
                for(int k=0; k<combinations; k++){
                    cout<<input[i]<<" "<<input[start]<<" "<<input[end]<<endl;
                }
                start=start+count1;
                end=end-count2;
            }
        }
    }
}
