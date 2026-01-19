/*
88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of
elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has
a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be
ignored. nums2 has a length of n.
*/


/*
OPTIMAL SOLUTION------------------------------------------------------

Using 3 pointers
- a pointer --> points to (m-1)th index of nums1  -- last valid element of nums1
- b pointer --> points to (m+n-1)th index of nums1 -- last element of nums1, for write operation
- c pointer --> points to (n-1)th index of nums2  -- last position of nums2

if nums1[a]>=nums[c]
        at nums[b] keep nums[a]
        a--
        k-- (at every step)
if nums1[a]<nums[c]
        at nums[b] keep nums[c]
        c--
        k--(at every step)

if all values of nums2 exhausted --> done with the merging
if elements remain in nums2 i.e j>=0 --> then add remaining values in nums1
    nums1[b]=nums2[j]
    j-- and k--  (while j>=0)

*/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums2[j]>=nums1[i]){
                nums1[k]=nums2[j];
                j--;
            }else if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }
            k--;
        }

        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};