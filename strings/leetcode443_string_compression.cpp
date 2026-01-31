/*
443. String Compression
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input 
character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Note: The characters in the array beyond the returned length do not matter and should be ignored.

Example 1:  

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Constraints:

1. 1 <= chars.length <= 2000
2. chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int read = 0;
        int write = 0;

        while(read<n){
            int count = 0;
            int current = chars[read];

            while (read<n && chars[read] == current)
            {
                read++; count++;
            }

            chars[write] = current;
            write++;

            if (count>1)
            {
                string str = to_string(count);
                for(char s:str){
                    chars[write] = s;
                    write++;
                }
            }
            
        }

        return write;
    }
};