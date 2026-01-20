/*
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_non_zero_found = 0;
        int current;

        for (int current = 0; current < nums.size(); current++)
        {
            if(nums[current]==0){
                continue;
            }else {
                nums[last_non_zero_found]=nums[current];
                last_non_zero_found ++;
            }
        }

        while (last_non_zero_found < nums.size())
        {
            nums[last_non_zero_found] = 0;
            last_non_zero_found++;
        } 
    }
};