/*
Problem statement
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.
*/

#include <bits/stdc++.h> 
using namespace std;

void reverseArray(vector<int> &arr , int m) {
    int n = arr.size();
    int left = m+1;
    int right = n-1;

    while(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }     	
}