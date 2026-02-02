/*
1047. Remove All Adjacent Duplicates In String
You are given a string s consisting of lowercase English letters. A duplicate removal consists of 
choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the 
answer is unique.

Example 1:
Input: s = "azxxzy"
Output: "ay"

Constraints:
a) 1 <= s.length <= 105
b) s consists of lowercase English letters.

*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int k = 0;  

        for (int i = 0; i < s.size(); i++) {
            s[k] = s[i];

            if (k > 0 && s[k] == s[k - 1]) {
                k--;   
            } else {
                k++;   
            }
        }

        return s.substr(0, k);
    }
    
};