#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

/* Merge 2 linked list in sorted order*/
Node* merge(Node* lst1,Node* lst2)
{   
    if (lst1 == NULL)
        return lst2;
 
    // If second linked list is empty then first
    // is the result
    if (lst2 == NULL)
        return lst1;
    Node* head = new Node(-1);
    Node* temp = head;
    while(lst1 != NULL && lst2 != NULL){
        if(lst1 -> data < lst2-> data){
            temp->bottom = lst1;
            lst1 = lst1->bottom;
            temp = temp->bottom;
        }
        else{
            temp->bottom = lst2;
            lst2 = lst2->bottom;
            temp = temp->bottom;
        }
    }
    while(lst1 != NULL){
        temp->bottom = lst1;
        lst1 = lst1->bottom;
        temp = temp->bottom;
    }
    while(lst2 != NULL){
        temp->bottom = lst2;
        lst2 = lst2->bottom;
        temp = temp->bottom;
    }
    head = head->bottom;
    return head;
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{   
    if(root == NULL || root-> next == NULL){
        return root;
    }
    Node *lst1 = root;
    Node *lst2 = flatten(root-> next);
    Node *temp = merge(lst1,lst2);
   
    return temp;
}