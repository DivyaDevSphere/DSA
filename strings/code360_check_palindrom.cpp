/*
Problem statement
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :
String 'S' is NOT case sensitive.
Example :

Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100 
1 <= Length(S) <= 10^4

Where 'T' denotes the number of test cases and 'S' denotes the given string.

Time Limit : 1 sec

*/

#include <bits/stdc++.h> 
using namespace std;

bool checkPalindrome(string s){
    int n = s.length();

    int left =0;
    int right = n-1;

    while (left<right)
    {
        while(left<right && !isalnum(s[left])){
            left++;
        }

        while(left<right && !isalnum(s[right])){
            right--;
        }

        if (tolower(s[left])!=tolower(s[right]))
        {
            return false;
        }
        
        left++;
        right--;

        
    }
    return true;
    
}