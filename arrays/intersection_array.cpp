/*
Problem statement
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.
*/

// solution ------------------------------------------------------------------------------

/*
solved using brute force--
I have applied the loop on both the arrays by maintaining an integer variable 'element' to store the duplicate 
integer of the array and then made that integer value equals to INT_MIN so that next the the iterartion happens
it doesn't count it again.
Also maintained a vector 'ans' to store the duplicate integers/intersection of two arrays 
*/
#include <bits/stdc++.h> 
using namespace std;

vector<int> intersection(vector<int> arr1, vector<int> arr2){
    vector<int> ans;
    for (int i = 0; i < arr1.size(); i++)
    {
        int element = arr1[i];
        for (int j = 0; j < arr2.size(); j++)
        {
            if (element == arr2[j])
            {
                ans.push_back(element);
                arr2[j]= INT_MIN;
                break;
            }
        } 
    }
    return ans;
    
}