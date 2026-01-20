/*
189. Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5


*/

#include <bits/stdc++.h> 
using namespace std;\

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size()==0){  // edge case
            return;
        }

        k= k % nums.size();
        
        reverse(nums.begin(),nums.end());

        // reversing first k elements
        reverse(nums.begin(),nums.begin()+k);

        // reversing k to n-1 elements for maintaing relative order
        reverse(nums.begin()+k,nums.end());

        
        
    }
};