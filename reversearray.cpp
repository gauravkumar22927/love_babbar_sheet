#include<iostream>

using namespace std;
/*void reverse_arr(int arr[],int n){
  int i = 0;int j = n-1;
  while(i<=j){
    swap(arr[i],arr[j]);
    i++;
    j--;
  }
}*/

void reverse_rec(int arr[],int start,int end){
  if(start <= end){
    swap(arr[start],arr[end]);
    reverse_rec(arr,start+1,end-1);
  }
}
int main(){
  int arr[] = {1,2,3,4,5,6,7,8};
  int n = sizeof(arr)/sizeof(arr[0]);

  //reverse_arr(arr,n);
  reverse_rec(arr,0,n-1);
  cout << endl;
  for(int i = 0;i<n;i++){
    cout << arr[i] << " ";
  }
}