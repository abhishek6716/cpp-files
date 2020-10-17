#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> myvector{ 1, 2, 3, 4, 5 };
    vector<int>::iterator it=myvector.end();
    cout<<(*it)<<endl;                                     // output=0;
}

///////////////////////////  vector initialisation ////////////////////////////////
/*
// create an empty vector and push values one by one. 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    // Create an empty vector 
    vector<int> vect; 
  
    vect.push_back(10); 
    vect.push_back(20); 
    vect.push_back(30); 
  
    for (int x : vect) 
        cout << x << " "; 
  
    return 0; 
} 
///// 10 20 30 //////
*/
///////////////////////////////////////////////////////////////////////////////

/*
// create an empty vector and push values one by one. 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    int n = 3; 
  
    // Create a vector of size n with 
    // all values as 10. 
    vector<int> vect(n, 10); 
  
    for (int x : vect) 
        cout << x << " "; 
  
    return 0; 
} 
////////  10 10 10 ///////
*/
///////////////////////////////////////////////////////////////////////////////
/*
// Initialize a vector like an array. 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    vector<int> vect{ 10, 20, 30 }; 
  
    for (int x : vect) 
        cout << x << " "; 
  
    return 0; 
} 
////// 10 20 30 ///////
*/
///////////////////////////////////////////////////////////////////////////////
/*
// Initialize a vector from an array. 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    int arr[] = { 10, 20, 30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    vector<int> vect(arr, arr + n); 
  
    for (int x : vect) 
        cout << x << " "; 
  
    return 0; 
} 
///// 10 20 30 //////
*/
///////////////////////////////////////////////////////////////////////////////
/*
// Initialize a vector from another vector. 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    vector<int> vect1{ 10, 20, 30 }; 
  
    vector<int> vect2(vect1.begin(), vect1.end()); 
  
    for (int x : vect2) 
        cout << x << " "; 
  
    return 0; 
} 
///// 10 20 30 /////
*/
///////////////////////////////////////////////////////////////////////////////
/*
// Initializing all elements with a particular value :
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    vector<int> vect1(10); 
    int value = 5; 
    fill(vect1.begin(), vect1.end(), value); 
    for (int x : vect1) 
        cout << x << " "; 
} 
///// 5 5 5 5 5 5 5 5 5 5 ////
*/
///////////////////////////////////////////////////////////////////////////////