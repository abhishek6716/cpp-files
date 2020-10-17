///////////////////////  lowest common prefix /////////////////////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//////////////////// word by word matching approach ///////////////////
string commonPrefix(string s1, string s2)
{
    if (s1.length() == 0 || s2.length() == 0)
    {
        return "";
    }
    string output;
    for (int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++)
    {
        if (s1[i] != s2[j])
        {
            break;
        }
        output.push_back(s1[i]);
    }
    return output;
}
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        prefix = commonPrefix(prefix, strs[i]);
        if (prefix[0] == '""')
        {
            break;
        }
    }
    return prefix;
}

////////////////// char by char matching approach /////////////////////
// A Function to find the string having the minimum length and returns that length
int findMinLength(string arr[], int n)
{
    int min = arr[0].length();

    for (int i = 1; i < n; i++)
        if (arr[i].length() < min)
            min = arr[i].length();

    return (min);
}

// A Function that returns the longest common prefix from the array of strings
string commonPrefix(string arr[], int n)
{
    int minlen = findMinLength(arr, n);

    string result; // Our resultant string
    char current;  // The current character

    for (int i = 0; i < minlen; i++)
    {
        // Current character (must be same in all strings to be a part of result)
        current = arr[0][i];

        for (int j = 1; j < n; j++)
            if (arr[j][i] != current)
                return result;

        // Append to result
        result.push_back(current);
    }

    return (result);
}

//////////////////////// divide ans conquor approach //////////////////
// A Utility Function to find the common prefix between strings- str1 and str2
string commonPrefixUtil(string str1, string str2)
{
    string result;
    int n1 = str1.length(), n2 = str2.length();

    for (int i = 0, j = 0; i <= n1 - 1 && j <= n2 - 1; i++, j++)
    {
        if (str1[i] != str2[j])
            break;
        result.push_back(str1[i]);
    }
    return (result);
}

// A Divide and Conquer based function to find the longest common prefix. This is similar to the merge sort technique
string commonPrefix(string arr[], int low, int high)
{
    if (low == high)
        return (arr[low]);

    if (high > low)
    {
        // Same as (low + high)/2, but avoids overflow for large low and high
        int mid = low + (high - low) / 2;

        string str1 = commonPrefix(arr, low, mid);
        string str2 = commonPrefix(arr, mid + 1, high);

        return (commonPrefixUtil(str1, str2));
    }
}