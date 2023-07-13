// Question Link :
// Code Studio : https://www.codingninjas.com/studio/problems/zero-matrix_1171153?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTab=3

#include <bits/stdc++.h> 
// Brute Force

// void setZero(vector<vector<int>> &matrix, int n, int m, int row, int col){
// 	// col wise traversal
// 	for(int i=0; i<m; i++){
// 		if(matrix[row][i] == 0){
// 			continue;
// 		}
// 		// converting non-zeroes values to -1;
// 		matrix[row][i] = -1;
// 	}
// 	// row wise traversal
// 	for(int i=0; i<n; i++){
// 		if(matrix[i][col] == 0){
// 			continue;
// 		}
// 		matrix[i][col] = -1;
// 	}
// }
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
// 	// Write your code here.
	
// 	for(int i=0; i<n; i++){
// 		for(int j=0; j<m; j++){
// 			if(matrix[i][j] == 0){
// 				setZero(matrix, n, m, i, j);
// 			}
// 		}
// 	}
	
// 	// converting cells having -1 value to 0;
// 	for(int i=0; i<n; i++){
// 		for(int j=0; j<m; j++){
// 			if(matrix[i][j] == -1){
// 				matrix[i][j] = 0;
// 			}
// 		}
// 	}
// 	return matrix;
// }



// DP | TC:O(mn) | SC: O(mn)
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	bool firstRowHasZero = false;
	bool firstColHasZero = false;

	// check if 1st row has zero
	for(int i=0; i<m; i++){
		if(matrix[0][i] == 0){
			firstRowHasZero = true;
			break;
		}
	}
	// check if 1st col has zero
	for(int i=0; i<n; i++){
		if(matrix[i][0] == 0){
			firstColHasZero = true;
			break;
		}
	}
	
	// use first row and first col to mark zero rows and columns
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[i][j] == 0){
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	// set 0 based on marks in the first row and column
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[0][j] == 0 || matrix[i][0] == 0){
				matrix[i][j] = 0;
			}
		}
	}

	// set 0s for 1st row, if necessary
	if(firstRowHasZero){
		for(int i=0; i<m; i++){
			matrix[0][i] = 0;
		}
	}

	// set 0s for 1st col if necessary
	if(firstColHasZero){
		for(int i=0; i<n; i++){
			matrix[i][0] = 0;
		}
	}

	return matrix;
}
