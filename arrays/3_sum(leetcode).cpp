/*
PROBLEM STATEMENT:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Constraints:

1. 3 <= nums.length <= 3000
2. -105 <= nums[i] <= 105
 
*/

/*
OPTIMAL SOLUTION:

I will solve this with the same approach(two pointer) as earlier just minor changes--
1. sort the array
2. create a loop to fix the first element (i=0,i<n-2,i++)
3. then to skip the duplicates i will check if i>0 and arr[i]!=arr[i-1]
4. assign indexes to left = i+1 and right = n-1
5. add all three to check if it is equal to zero, if yes will store as triplet and move left++ and right-- till no duplicates occur
6. if not equal to zero then if sum less than zero then left ++ otherwise right --;
*/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();
        int left;
        int right;

        sort(nums.begin(),nums.end());

        for (int i = 0; i < n-2; i++)
        {
            if (i>0 && nums[i] == nums[i-1])
            {
                continue;
            }

                left = i+1;
                right = n-1;

            while(left<right){

                int sum = nums[left]+nums[right]+nums[i];
                if (sum==0)
                {
                    vector<int> triplets;
                    triplets.push_back(nums[i]);
                    triplets.push_back(nums[left]);
                    triplets.push_back(nums[right]);

                    while (left<right && nums[left] == nums[left+1])
                    {
                        left++;
                    }
                    while (left<right && nums[right] == nums[right-1])
                    {
                        right--;
                    }

                    left++;
                    right--;

                    ans.push_back(triplets);
                }
                else if(sum<0){
                        left++;
                    
                }else{
                    right--; 
                }
            
        }
        
    }
    return ans;
    }
    
};