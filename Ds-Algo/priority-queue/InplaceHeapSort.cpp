#include<iostream>
using namespace std;

void InplaceHeapSort(int pq[], int n){
    
    // Building heap in input array
    for(int i=1; i<n; i++){
        int CI=i;
        while(CI>0){
            int PI=(CI-1)/2;
            if(pq[PI]>pq[CI]){
                int temp=pq[CI];
                pq[CI]=pq[PI];
                pq[PI]=temp;
            }
            else{
                break;
            }
            CI=PI;
        }
    }

    // Remove elements
    int size=n;
    while(size>1){
        int temp=pq[0];
        pq[0]=pq[size-1];
        pq[size-1]=temp;

        size--;

        int PI=0;
        int LCI=2*PI+1;
        int RCI=2*PI+2;
        while(LCI<size){
            int minI=PI;
            if(pq[minI]>pq[LCI]){
                minI=LCI;
            }
            if(RCI<size && pq[minI]>pq[RCI]){
                minI=RCI;
            }
            if(minI==PI){
                break;
            }
            int temp=pq[minI];
            pq[minI]=pq[PI];
            pq[PI]=temp;

            PI=minI;
            LCI=2*PI+1;
            RCI=2*PI+2;
        }
    }
}

int main(){
    int arr[]={5,2,1,0,3,8,7};
    InplaceHeapSort(arr, 7);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}