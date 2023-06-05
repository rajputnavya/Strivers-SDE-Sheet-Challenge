// Question Link : https://www.codingninjas.com/codestudio/problems/sort-0-1-2_8230695?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int zeroIndex = 0;
   int twoIndex = n-1;
   int i = 0;
   while(i <= twoIndex){
      if(arr[i] == 0){
         swap(arr[zeroIndex], arr[i]);
         zeroIndex++;
         i++;
      }
      else if(arr[i] == 2){
         swap(arr[i], arr[twoIndex]);
         twoIndex--;
      }
      else if(arr[i] == 1){
         i++;
      }
   }
   
}
