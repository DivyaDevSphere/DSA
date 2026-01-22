/*
Problem statement
You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element 
represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.

Note:

1. The length of each array is greater than zero.

2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer 
represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.

3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^2
1 <= N, M <= 10^4
0 <= A[i], B[i] <= 9

Time Limit: 1 sec
*/

/*
My uderstanding

You are given two non-empty arrays where each array represents a non-negative integer, with each element storing a single digit. The digit 
at index 0 is the most significant digit. The two arrays can be of different lengths. You must compute the sum of the two numbers and return
the result as an array of digits, again with the most significant digit at index 0 and no leading zeros.

*/

/*
OPTIMAL SOLUTION-----------------------------------------

We use two pointers, starting from the last index of each array (least significant digits).

We maintain a carry variable, initialized to 0.

At each step, we calculate:

sum = (digit from A if i >= 0 else 0) + 
      (digit from B if j >= 0 else 0) + 
      carry


Push sum % 10 i.e remainder into the result array.

Update carry = sum / 10  i.e quotient.

Move pointers: i--, j--.

Loop continues until:

i >= 0 || j >= 0 || carry > 0


At the end, the result array is reversed because digits were pushed from least significant to most significant.

This approach handles all edge cases:

Different lengths of arrays

Carry propagation to a new most significant digit

One array exhausted before the other

Time Complexity: O(max(N, M)) — each digit is processed exactly once
Space Complexity: O(max(N, M) + 1) — result array to store digits + constant extra space

*/

#include <bits/stdc++.h> 
using namespace std;

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1;
    int j = m-1;
    int carry = 0;
    int sum = 0;
    vector<int> ans;

    while (i>=0||j>=0||carry>0)
    {
        sum = (i>=0?a[i]:0) + (j>=0?b[j]:0) +carry;
        carry = sum/10;
        ans.push_back(sum%10);
        i--;
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}