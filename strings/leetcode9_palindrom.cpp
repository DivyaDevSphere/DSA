/*
9. Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.

NOTE:

1. Negative int = always !palindrom
2. Numbers ending with zero = !palindrom  except 0
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        return (x == reversedHalf || x == reversedHalf / 10);
    }  
};