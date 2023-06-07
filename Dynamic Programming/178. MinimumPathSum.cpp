// Question Link :
// Code Studio : https://www.codingninjas.com/codestudio/problems/minimum-path-sum_8230791?challengeSlug=striver-sde-challenge
// Leetcode : 

// APPROACH 1 - MEMOIZATION
// TC : O(m*n)
// SC : O(m*n)

#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid, int m, int n, int i, int j, int **output){
    // Base Case
    if(i == m-1 && j == n-1){
        return grid[i][j];
    }
    // Edge Case
    if(i >= m || j >= n){
        return INT_MAX;
    }
    // Checking if value already exists
    if(output[i][j] != -1){
        return output[i][j];
    }
    // Calculate ans save value if not exists
    int x = minSumPath(grid, m, n, i, j+1, output);
    int y = minSumPath(grid, m, n, i+1, j, output);
    output[i][j] = min(x, y) + grid[i][j];
    return output[i][j];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size(); // rows
    int n = grid[0].size(); //columns
    // Output array
    int **output = new int *[m];
    for(int i=0; i<m; i++){
        output[i] = new int[n];
    }
    // Initialising output array with -1
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            output[i][j] = -1;
        }
    }
    return minSumPath(grid, m, n, 0, 0, output);
}


// APPROACH 2 (Optimised) - DP

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size(); // rows
    int n = grid[0].size(); //columns

    int **output = new int *[m];
    for(int i=0; i<m; i++){
        output[i] = new int[n];
    }
    
    output[m-1][n-1] = grid[m-1][n-1];
    
    for(int j=n-2; j>=0; j--){
        output[m-1][j] = output[m-1][j+1] + grid[m-1][j];
    }
    for(int i=m-2; i>=0; i--){
        output[i][n-1] = output[i+1][n-1] + grid[i][n-1];
    }
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            output[i][j] = min(output[i+1][j], output[i][j+1]) + grid[i][j];
        }
    }
    return output[0][0];
}

