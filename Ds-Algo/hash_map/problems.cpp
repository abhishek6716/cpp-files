#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;

char* uniqueChar(char *str){
    int len=strlen(str);
    if(len==0){
        char *ans=new char[1];
        ans[0]='\0';
        return ans;
    }
    char *ans=new char[len+1];
    unordered_map<char, bool> map;
    int i=0;
    for(int currIndex=0; currIndex<len; currIndex++){
        if(map.count(str[currIndex])==0){
            map[str[currIndex]]=true;
            ans[i]=str[currIndex];
            i++;
        }
    }
    ans[i]='\0';
    return ans;
}


vector<int> longestConsIncSeq(int *arr, int n){
    unordered_map<int, bool> visitedElements;
    unordered_map<int, int> eleToIndMap;
    for(int i=0; i<n; i++){
        eleToIndMap[arr[i]]=i;
        if(visitedElements.count(arr[i])==0){
            visitedElements[arr[i]]=true;
        }
    }
    vector<int> longSeq;
    int globalMaxSeqLen=1;
    int globalMinStartIndex=0;
    for(int i=0; i<n; i++){
        int num=arr[i];
        int currMinStartIndex=i;
        int count=0;
        int tempNum=num;
        
        // forward
        while(visitedElements.count(tempNum)==1 && visitedElements[tempNum]==true){
            visitedElements[tempNum]=false;
            count++;
            tempNum++;
        }

        // backward
        tempNum=num-1;
        while(visitedElements.count(tempNum)==1 && visitedElements[tempNum]==true){
            visitedElements[tempNum]=false;
            count++;
            currMinStartIndex=eleToIndMap[tempNum];
            tempNum--;
        }

        if(count>globalMaxSeqLen){
            globalMaxSeqLen=count;
            globalMinStartIndex=currMinStartIndex;
        }
        else if(count==globalMaxSeqLen){
            if(currMinStartIndex<globalMinStartIndex){
                globalMinStartIndex=currMinStartIndex;
            }
        }
    }
    int globalStartNum=arr[globalMinStartIndex];
    longSeq.push_back(globalStartNum);
    globalMaxSeqLen--;

    while(globalMaxSeqLen!=0){
        globalStartNum++;
        longSeq.push_back(globalStartNum);
        globalMaxSeqLen--;
    }
    return longSeq;
}


void printPairs(int *input, int n, int k){
    unordered_map<int, int> map;
    for(int i=0; i<n; i++){
        int key=input[i];
        map[key]++;
    }
    for(int i=0; i<n; i++){
        int key=input[i];
        if(k==0){
            int a=map[key];
            int count=(a*(a-1))/2;
            for(int i=0; i<count; i++){
                cout<<key<<" "<<key<<endl;
            }
        }
        else{
            int a=key+k;
            int b=key-k;
            int count=map[key];
            int count1=map[a];
            int count2=map[b];

            for(int j=0; j<count*count1; j++){
                cout<<min(a, key)<<" "<<max(a, key)<<endl;
            }
            for(int j=0; j<count*count2; j++){
                cout<<min(b, key)<<" "<<max(b, key)<<endl;
            }
        }
        map.erase(key);
    }
}

int lengthOfLongestSubsetSumZero(int *arr, int n){
    unordered_map<int, int> map;
    for(int i=1; i<n; i++){
        arr[i]=arr[i]+arr[i-1];
    }
    int m=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            if(m<i+1){
                m=i+1;
            }
        }
        else if(map.count(arr[i])>0){
            if(m<i-map[arr[i]]){
                m=i-map[arr[i]];
            }
            else{
                map[arr[i]]=i;
            }
        }
        return m;
    }
}