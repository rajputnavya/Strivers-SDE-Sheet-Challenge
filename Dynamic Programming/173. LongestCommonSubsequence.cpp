// Question Link : 
// Code Studio : https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_8230681?challengeSlug=striver-sde-challenge
// LeetCode : https://leetcode.com/problems/longest-common-subsequence/submissions/966173285/


// Approach : DP
// TC : O(m*n)
// SC : O(m*n)

int lcs(string s, string t)
{
	//Write your code here
	int m = s.size();
	int n = t.size();

	// Creating Output array
	int **output = new int *[m+1];
	for(int i=0; i<=n; i++){
		output[i] = new int[n+1];
	}

	// Filling 1st row
	for(int j=0; j<=n; j++){
		output[0][j] = 0;
	}

	// Filling 1st column
	for(int i=1; i<=m; i++){
		output[i][0] = 0;
	}

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			// Check if 1st character matches
			if(s[m-i] == t[n-j]){
				output[i][j] = 1 + output[i-1][j-1];
			}
			else{
				int a = output[i-1][j];
				int b = output[i-1][j-1];
				int c = output[i][j-1];
				output[i][j] = max(a, max(b,c));
			}
		}
	}
	return output[m][n];
}
