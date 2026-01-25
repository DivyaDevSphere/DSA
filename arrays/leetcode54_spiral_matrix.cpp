/*
54. Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

/*
1. Spiral order traversal means visiting all elements of the matrix layer by layer, starting from the outer boundary 
and moving inward, traversing top row → right column → bottom row → left column repeatedly.
2. Traversal starts from the top-left element of the matrix.
3. The traversal direction is clockwise.
4. The output is a 1D vector (or list) containing all matrix elements in spiral order.
5. The input matrix remains unchanged; elements are read and stored in a separate result vector.

Right → (0, +1)
Down → (+1, 0)
Left → (0, -1)
Up → (-1, 0)

*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited;

        int i =0;
        int j =0;
        while(matrix[i][j] != NULL && visited[i][j] != true){
            
        }
    }
};