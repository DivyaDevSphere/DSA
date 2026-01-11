/*
Problem statement
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

Note:

Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.
*/

// solution------------------------------------------------------------------------------------

/*
my approach- the iterated the vector using two loops and at each step compared the sum of integers with the target
whenever the target integer is achieved i have pushed the vector integer into the vector 'ans'. The solution demanded
a sorted vector 'ans' on the basis of the first integer of the sub-vector, therefore at the end i have sorted the vector.
Time: O(n²)
Space: O(n²)
*/

#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
   for(int i =0; i<arr.size();i++){
      for(int j=i+1 ;j<arr.size() ;j++){
         if( arr[i]+arr[j] == s){
            vector<int> pair;
            pair.push_back(min(arr[i],arr[j]));
            pair.push_back(max(arr[i],arr[j]));
            ans.push_back(pair);
         }
      }
   }
   sort(ans.begin(),ans.end());
   return ans;
}