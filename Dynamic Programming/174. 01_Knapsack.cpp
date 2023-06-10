// Question Link : 
// Code Studio : https://www.codingninjas.com/codestudio/problems/0-1-knapsack_8230801?challengeSlug=striver-sde-challenge&leftPanelTab=3

int maxProfit(vector<int> &value, vector<int> &weight, int n, int maxWeight)
{
	// Recursive
  // TC : O(2^n)
  // SC : O(n)

	// int knapsack(int *weight, int *value, int n, int maxWeight) {
	// 	// Basecase
	// 	if(maxWeight == 0 || n==0){
	// 		return 0;
	// 	}

	// 	// Corner case
	// 	if(weight[0] > maxWeight){
	// 		return knapsack(weight+1, value+1, n-1, maxWeight);
	// 	}
	// 	// Including item at index 0
	// 	int x = knapsack(weight+1, value+1, n-1 maxWeight - weight[0]) + value[0];
	// 	// Not including item at index 0
	// 	int y = knapsack(weight+1, value+1, n-1, maxWeight);

	// 	return max(x, y);
	// }


	// Memoization
  // TC : O(mn)
  // SC : O(mn)

	// 	// Basecase
	// 	if(maxWeight == 0 || n==0){
	// 		return 0;
	// 	}
	// 	if(output[maxWeight][n] != -1){
	// 		return output[maxWeight][n];
	// 	}
	// 	// Corner case
	// 	if(weight[0] > maxWeight){
	// 		output[maxWeight][n] = knapsack(weight+1, value+1, n-1, maxWeight, output);
	// 		// return output[maxWeight][n];
	// 	}
	// 	else{
	// 		// Including item at index 0
	// 	int x = knapsack(weight+1, value+1, n-1, maxWeight - weight[0], output) + value[0];
	// 	// Not including item at index 0
	// 	int y = knapsack(weight+1, value+1, n-1, maxWeight, output);

	// 	output[maxWeight][n] = max(x, y);
	// 	}

	// 	return output[maxWeight][n];
	// }

	// int knapsack(int* weight,int*value,int n,int maxWeight){
	// 	int **output = new int *[maxWeight + 1];
	// 	for(int i=0; i<=maxWeight; i++){
	// 		output[i] = new int[n+1];
	// 	}
	// 	for(int i=0; i<=maxWeight; i++){
	// 		for(int j=0; j<=n; j++){
	// 			output[i][j] = -1;
	// 		}
	// 	}
	// 	knapsack(weight, value, n, maxWeight, output);
	// }

	// DP
  // TC : O(mn)
  // SC : O(mn)

	int **output = new int *[maxWeight + 1];
	for(int i=0; i<=maxWeight; i++){
		output[i] = new int [n + 1];
	}
	for(int i=0; i<=maxWeight; i++){
		for(int j=0; j<=n; j++){
			// Filling 1st row and 1st column
			if(i ==0 || j == 0){
				output[i][j] = 0;
			}
			if(i < weight[j-1]){
				output[i][j] = output[i][j-1];
			}
			else{
				int x = output[i][j-1];
				int y = value[j-1] + output[i-weight[j-1]][j-1];
				output[i][j] = max(x, y);
			}
		}
	}
	return output[maxWeight][n];
}
