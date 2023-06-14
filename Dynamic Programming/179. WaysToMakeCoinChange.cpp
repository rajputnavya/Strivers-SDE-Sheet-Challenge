// Question Link : 
// Code Studio : https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_8230691?challengeSlug=striver-sde-challenge

// Approach : DP

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    int *output = new int[value + 1];
    output[0] = 1;
    for(int i=1; i<=value; i++){
        output[i] = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=denominations[i]; j<=value; j++){
            output[j] = output[j] + output[j-denominations[i]];
        }
    }
    return output[value];
}
