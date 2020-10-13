#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> map;
    map["abc1"]=1;
    map["abc2"]=2;
    map["abc3"]=3;
    map["abc4"]=4;
    map["abc5"]=5;
    map["abc6"]=6;

    unordered_map<string, int>::iterator it;
    it=map.begin();
    while(it!=map.end()){
        cout<<"key: "<<it->first<<"value: "<<it->second<<endl;
        it++;
    }

    // find
    unordered_map<string, int>::iterator it2=map.find("abc3");
    // map.erase(it2, it2 + 4);
    
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it1=v.begin();
    while(it1!=v.end()){
        cout<<*it1<<endl;
        it++;
    }
}