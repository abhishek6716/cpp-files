#include<iostream>
#include<algorithm>
using namespace std;

void PairSum(int arr[], int size, int x){
    sort(arr, arr+size);

    int left=0;
    int right=size-1;
    while(left<right){
        if(arr[left]+arr[right]<x){
            left++;
        }
        else if(arr[left]+arr[right]>x){
            right--;
        }
        else{
            int tempLeft=arr[left];
            int leftCount=0;
            while(arr[left]==tempLeft){
                leftCount++;
                left++;
            }

            int tempRight=arr[right];
            int pairCount;
            if(tempLeft==tempRight){
                pairCount=(leftCount*(leftCount-1))/2;
            }
            else{
                int rightCount=0;
                while(arr[right]==tempRight){
                    rightCount++;
                    right--;
                }
                pairCount=leftCount*rightCount;
            }
            while(pairCount--){
                cout<<tempLeft<<" "<<tempRight<<endl;
            }
        }
    }
}