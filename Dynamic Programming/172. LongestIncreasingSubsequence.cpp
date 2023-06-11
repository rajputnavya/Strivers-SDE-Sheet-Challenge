// Question Link :
// Code Studio : https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_8230689?challengeSlug=striver-sde-challenge
// LeetCode : https://leetcode.com/problems/longest-increasing-subsequence/submissions/968832549/

// Approach : DP
// TC : O(n*n)
// SC : O(n)

int longestIncreasingSubsequence(int *arr, int n) {
	int *output = new int [n];
	output[0] = 1;
	for(int i=1; i<n; i++){
		output[i] = 1;
		for(int j = i-1; j>=0; j--){
			if(arr[j] >= arr[i]){
				continue;
			}
			int possibleAns = output[j] + 1;
			output[i] = max(output[i], possibleAns);
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		ans = max(ans, output[i]);
	}
	delete []output;
	return ans;
}
