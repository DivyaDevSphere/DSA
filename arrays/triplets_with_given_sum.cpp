/*
Problem statement
You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

Note:
1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
2. The elements in the array need not be distinct.
3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".
*/


/*
BRUTE FORCE SOLUTION
I used three nested loops with indices i < j < k to ensure all indices are distinct and no index
combinations repeat.
For every triplet (arr[i], arr[j], arr[k]), I checked if their sum equals K.
To avoid duplicate triplets due to different ordering of values, I have sorted each valid triplet and
store it in a set, which guarantees uniqueness.

time complexity -- (On^3logn)
space -- (On2)
*/

#include <bits/stdc++.h> 
using namespace std;

// brute force ---------------------------------------------------
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    set<vector<int>> triplet;
    int var;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            var = arr[i]+arr[j];
            for (int k = j+1; k < n; k++)
            {
                if(var+arr[k]==K ){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(temp.begin(),temp.end());
                    triplet.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(triplet.begin(),triplet.end());
    return ans;
    
}

/*
OPTIMAL SOLUTION:
“I first sort the array. Then I iterate i from 0 to n-3 and fix arr[i] as the first element of the
triplet.
For each i, I use two pointers: left = i + 1 and right = n - 1.
I compute target = K - arr[i] and compare arr[left] + arr[right] with target.
If the sum is smaller, I move left++; if larger, I move right--.
When a valid triplet is found, I store it and skip duplicate values of left and right.
I also skip duplicate values of arr[i] to avoid repeating triplets.

Sorting already handles duplicates

time complexity -- (On^2)
space complexity -- (O1)
*/

// OPTIMAL SOLUTION----------------------------------------------
vector<vector<int>> findTriplets(vector<int>arr, int n, int K){

    vector<vector<int>> ans;
    int left;
    int right;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n-2; i++)
    {
        int first_element = arr[i];
        if (arr[i] == arr[i-1] && i>0)
        {
            continue;
        }
        
            int target = K - first_element;

            left = i+1;
            right = n-1;

            while (left < right){
                if((arr[left] + arr[right]) > target){
                    right--;
                }
                else if((arr[left] + arr[right]) < target){
                    left ++;
                }
                else{
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[left]);
                    while (left< right && arr[left] == arr[left+1])
                    {
                        left++;
                    }
                    
                    triplet.push_back(arr[right]);
                    while (left< right && arr[right] == arr[right-1])
                    {
                        right--;
                    }
                    
                    right--;
                    left++;
                    ans.push_back(triplet);

                }
            }
    }

    return ans;
}
