// Question Link : https://www.codingninjas.com/codestudio/problems/merge-two-sorted-arrays_8230835?challengeSlug=striver-sde-challenge                


#include <bits/stdc++.h>

vector<int> ninjaAndSortedArraysHelper(vector<int>& arr1, vector<int>& arr2, int m, int n){
	vector<int> v;
	int i = 0, j = 0;
	while((i < arr1.size()) && (j < arr2.size())){
		if(arr1[i] < arr2[j]){
			v.push_back(arr1[i++]);
		}
		else if(arr1[i] >= arr2[j]){
			v.push_back(arr2[j++]);
		}
	}
	while(i < arr1.size()){
		v.push_back(arr1[i++]);
	}
	while(j < arr2.size()){
		v.push_back(arr2[j++]);
	}

	return v;
}

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {

	vector<int> arr3;
	for(int i=0; i<arr1.size(); i++){
		if(arr1[i] != 0){
			arr3.push_back(arr1[i]);
		}
	}
	return ninjaAndSortedArraysHelper(arr3, arr2, m, n);
}
