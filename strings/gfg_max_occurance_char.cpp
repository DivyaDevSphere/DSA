/*
Most Frequent Character

Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the 
string s. If more than one character occurs the maximum number of times then print the lexicographically 
smaller character.

*/
/*

BRUTE FORCE---------------------------------------------------------------

For each character in the string, I count its frequency by comparing it with every other character using a nested loop. I maintain a maxFreq variable and an answerChar.
If the current character’s frequency is greater than maxFreq, I update both.
If the frequency is equal to maxFreq, I compare characters and keep the lexicographically smaller one.

*/

/*

OPTIMAL APPROACH-----------------------------------------------------------

Use a frequency array of size 26, not a hashmap.

Reason:

1. Input is only lowercase letters
2. Fixed-size array is faster and memory-efficient
3. Avoids hashing overhead

| Approach             | Time | Space  |
| -------------------- | ---- | ------ |
| HashMap              | O(n) | O(n)   |
| Frequency Array (26) | O(n) | O(1)   |

because we are considering it as array of size 26 which is fixed through out the program whereas 
hashmap size can varry with the size of input.

*/
#include <bits/stdc++.h> 
using namespace std;

char getMaxOccuringChar(char* str) {
    int arr[26] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        arr[str[i] - 'a']++;
    }

    int maxFreq = 0;
    char answerChar;

    for (int i = 0; i < 26; i++) {
        if (arr[i] > maxFreq) {
            maxFreq = arr[i];
            answerChar = 'a' + i;
        }
    }
    return answerChar;
}