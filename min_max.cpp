#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void find_min_max(int *arr,int n){
  int min = INT_MAX;
  int max = INT_MIN;
  cout << min << " " << max << " " << endl;
  for(int i = 0;i<n;i++){
    if(arr[i] < min){
      min = arr[i];
    }
    if(arr[i] > max){
      max = arr[i];
    }
  }
  cout << min << " " << max << " " << endl; 

}

int main(){
  int arr[] = {1,-3,5,6,9,8,7,4,2};
  int n = sizeof(arr)/sizeof(arr[0]);

  find_min_max(arr,n);
}