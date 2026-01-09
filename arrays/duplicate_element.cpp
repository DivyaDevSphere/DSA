/*
Problem statement
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

For example:

Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
Note :
A duplicate number is always present in the given array.

*/

// solution -----------------------------------------------------------------------------------

/*
This function finds the duplicate element in an array using the XOR (^) operation.

It first XORs all elements of the array.
Then it XORs all numbers from 1 to n-1 (where n is the array size).
Since XOR of the same numbers cancels out (x ^ x = 0), all unique numbers are eliminated.
The remaining value is the duplicate element.

Key points:
Time Complexity: O(n)
Space Complexity: O(1)

*/
#include<stdio.h>
#include<vector>
using namespace std;

int findDuplicate(vector<int> &arr) 
{
    int ans=0;
    
    for(int i=0;i<arr.size();i++){
        ans = ans^arr[i];
    }
	for(int i=1; i<arr.size();i++ ){
        ans = ans^i;
    }
    return ans;
}
