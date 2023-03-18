#include<iostream>
#include<queue>

using namespace std;
class compare{
public:
  bool operator()(int a,int b){
    return a>b; // < for reverse
  }
};
int main(){
  priority_queue<int , vector<int> , compare > heap;

  int arr[] = { 1,2,3,4,5,8,6,7,12,14};
  for(auto x:arr){
    heap.push(x);
  }

  while(!heap.empty()){
    cout << heap.top() << " " << endl;
    heap.pop();
  }
  
}