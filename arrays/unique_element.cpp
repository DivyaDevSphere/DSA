/*
Problem statement
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

You need to find and return that number which is unique in the array/list.

Note:
Unique element is always present in the array/list according to the given condition.*/



// solution-------------------------------------------------------------------------------------

/*
Using XOR--
    we know that a^a = 0 
    a^0 = a

    Therefore with this solution -- XORing all the elements of the array, the duplicate elements will cancel
    each other out but  the unique element will remain as our answer.
*/
#include<stdio.h>
using namespace std;

int find_unique(int arr[], int size){
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}