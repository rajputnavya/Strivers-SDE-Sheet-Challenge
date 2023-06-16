// Question Link : 
// Code Studio : https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_8230769?challengeSlug=striver-sde-challenge

// Approach : Memoization
#include <bits/stdc++.h> 
int matrixChainMultiplication_helper(vector<int> &arr, int si, int ei,int** output){
    // Base Case
    if(si == ei-1 || si == ei){
        return 0;
    }
    if(output[si][ei] != -1){
        return output[si][ei];
    }
    int countMin = INT_MAX;
    for(int i = si+1;i<=ei-1;i++){
        countMin = min(countMin,matrixChainMultiplication_helper(arr,si,i,output)+matrixChainMultiplication_helper(arr,i,ei,output)+(arr[si]*arr[i]*arr[ei]));
        output[si][ei] = countMin;
    }

    return output[si][ei];
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    int** output = new int*[n+1];
    for(int i = 0;i<=n;i++){
        output[i] = new int[n+1];
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            output[i][j] = -1;
        }
    }
    return matrixChainMultiplication_helper(arr,0,n-1,output);
}
