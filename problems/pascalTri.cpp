#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> PascalTriangle(int numRows){
    vector<vector<int>> triangle;
    if(numRows==0){
        return triangle;
    }

    triangle.push_back({1});

    for(int i=1; i<numRows; i++){
        vector<int> v(i+1, 1);
        for(int j=1; j<i; i++){
            v[j]=triangle[i-1][j-1]+triangle[i-1][j];
        }
        triangle.push_back(v);
    }
    return triangle;
}
/*
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

or

[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/
