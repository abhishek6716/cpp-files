#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string, int> map;
    
    //insert
    pair<string, int> p1;                                  // we can also use constructor of pair class
    p1.first="abcd";
    p1.second=1;
    pair<string, int> p2("abc", 1);                        // By using constructor of pair class 
    map.insert(p2);
    map["def"]=2;

    // find or access
    cout<<map["abc"]<<endl;
    cout<<map.at("abc")<<endl;

    // cout<<map.at("xyz")<<endl;                          // gives error
    // cout<<map["xyz"]<<endl;                             // makes a new pair and gives value to 0 Bydefault  

    // checking presence of key
    if(map.count("abc")>0){                                // one map has only one key
        cout<<"abc is present"<<endl;
    }

    cout<<"size: "<<map.size()<<endl;
    map.erase("abc");
    cout<<"size: "<<map.size()<<endl;
}