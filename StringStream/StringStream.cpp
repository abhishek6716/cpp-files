#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include<map>
using namespace std;

/*
clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object.
*/

// program to count words in a string using stringstream. 
int countWords(string str) 
{ 
    // breaking input into word using string stream 
    stringstream s(str);         // Used for breaking words 
    string word;                 // to store individual words 
  
    int count = 0; 
    while (s >> word) 
        count++; 
    return count; 
} 


// program to demonstrate use of stringstream to count frequencies of words.  
void printFrequency(string st) 
{ 
    // each word it mapped to it's frequency 
    map<string, int> FW; 
    stringstream ss(st); // Used for breaking words 
    string Word; // To store individual words 
  
    while (ss >> Word) 
        FW[Word]++; 
  
    map<string, int>::iterator m; 
    for (m = FW.begin(); m != FW.end(); m++) 
        cout << m->first << " -> "
             << m->second << "\n"; 
}


// C++ program to remove spaces using stringstream 
// Function to remove spaces 
string removeSpaces(string str) 
{ 
    stringstream ss; 
    string temp; 
  
    // Storing the whole string 
    // into string stream 
    ss << str; 
  
    // Making the string empty 
    str = ""; 
  
    // Running loop till end of stream 
    while (!ss.eof()) { 
  
        // Extracting word by word from stream 
        ss >> temp; 
  
        // Concatenating in the string to be 
        // returned 
        str = str + temp; 
    } 
    return str; 
} 


// C++ program to remove spaces using stringstream and getline()  
// Function to remove spaces 
string removeSpaces(string str) 
{ 
    // Storing the whole string 
    // into string stream 
    stringstream ss(str); 
    string temp; 
  
    // Making the string empty 
    str = ""; 
  
    // Running loop till end of stream 
    // and getting every word 
    while (getline(ss, temp, ' ')) { 
        // Concatenating in the string 
        // to be returned 
        str = str + temp; 
    } 
    return str; 
} 
