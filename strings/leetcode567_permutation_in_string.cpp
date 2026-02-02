/*
567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Constraints:

1. 1 <= s1.length, s2.length <= 10^4
2. s1 and s2 consist of lowercase English letters.
*/

/*
MY UNDERSTANDING OF PROBLEM:
Given strings s1 and s2, determine if any permutation of s1 exists as a substring in s2. A 
permutation is a rearrangement of characters in s1. Return true if such a substring exists in s2, 
otherwise false. Both strings contain only lowercase letters and have length 1 ≤ len ≤ 10⁴.

s1 = "aab", s2 = "baa" -> true
s1 = "aab", s2 = "aba" -> false

*/

/*
OPTIMAL APPROACH:

1. Initialization

Create a frequency array freq1[26] for string s1.
Create a frequency array freq2[26] for the sliding window in s2.
Initialize two pointers left = 0, right = 0.

2. Expanding the window

Move right forward one step at a time.
For each right, increment the frequency of s2[right] in freq2.

3. Shrinking the window

If the window size (right - left + 1) becomes greater than s1.length(),
decrement the frequency of s2[left] in freq2 and move left forward.

4. Checking for permutation

When the window size is exactly equal to s1.length(),
compare freq1 and freq2.
If they are equal, return true.

5. Final result

If no window matches after the loop, return false.
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {
            freq2[s2[right] - 'a']++;

            if (right - left + 1 > s1.size()) {
                freq2[s2[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == s1.size()) {
                if (isEqual(freq1, freq2))
                    return true;
            }
        }

        return false;
    }

    bool isEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]){
                 return false;
            }
        }
        return true;
    }
};
