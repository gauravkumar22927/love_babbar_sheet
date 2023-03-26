#include<iostream>
#include<string>

using namespace std;

class node{
public:
  int data;
  node *next;

  node(int d){
    data = d;
    next = NULL;
  }
};

void insert(node * &head,node* &tail,int d){
  if(head == NULL){
    node* n = new node(d);
    head = n;
    tail = n;
  }
  else{
    node* n = new node(d);
    node* temp = head;
    n->next = temp;
    head = n;
  }
}

void print(node* head){
  if(head == NULL){
    return;
  }
  while(head != NULL){
    cout << head-> data << "->";
    head = head->next;
  }
}
node* floys_detect_loop(node *head){
  node *slow = head;
  node *fast = head;
  while(slow!= NULL && fast != NULL){
    slow = slow->next;
    fast = fast->next;
    if(fast != NULL){
      fast = fast->next;
    }
    if((slow == fast) && (fast != NULL)){
    return slow;
  }
  }
  return NULL;
}
void remove_loop(node* &head,node* intersect){
  node *slow = head;
  
  while(slow != intersect){
    slow = slow->next;
    intersect = intersect ->next;
  }
  node * temp = slow;

  while(temp->next != slow){
    temp = temp->next;
  }
  temp->next = NULL;
}
int main(){
  node *root = NULL;
  node *tail = NULL;

  insert(root,tail,2);
  insert(root,tail,4);
  insert(root,tail,6);
  insert(root,tail,8);
  insert(root,tail,3);
  insert(root,tail,5);
  insert(root,tail,11);
  insert(root,tail,12);
  insert(root,tail,14);

  print(root);
  cout << endl;

  tail->next = root->next->next->next;
  node* intersection = floys_detect_loop(root);
  string res;
  if(intersection == NULL){
    res = "No loop";
  }
  else{
    res = "Loop Exist";
  }
  cout << res << endl;
  remove_loop(root,intersection);
  print(root);
  
}