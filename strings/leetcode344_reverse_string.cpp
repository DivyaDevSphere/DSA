/*
344. Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.

*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int first = 0;
        int second = s.size()-1;

          while(first<=second){
            swap(s[first],s[second]);
            first++;
            second--;
        }
       
        
    }
};