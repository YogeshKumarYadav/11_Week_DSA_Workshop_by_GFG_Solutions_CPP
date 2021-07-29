#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{   /*    
    if(head1 == NULL || head2 == NULL)
        return -1;
    unordered_map<Node*, int> mp;
    Node *t = head1;
    while(t != NULL)
    {   mp[t]++;
        t = t->next;
    }
    t = head2;
    while(t != NULL)
    {   mp[t]++;
        if(mp[t] > 1)
            return t->data;
        t = t->next;    
    }
    return -1;
    //Execution Time:1.71
    */   
    if(head1 == NULL || head2 == NULL)
        return -1;
    Node *a = head1, *b = head2;
    while(a != b)
    {
        if(a == NULL)
            a = head2;
        else
            a = a->next;
        
        if(b == NULL)
            b = head1;
        else
            b = b->next;
    }
    return a->data;
    //Execution Time:0.61
}

