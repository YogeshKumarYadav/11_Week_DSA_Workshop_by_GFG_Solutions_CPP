
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverselist(struct Node *head)
    {
        Node *a = NULL, *b = head, *c = NULL;
        while(b != NULL)
        {   c = b->next;
            b->next = a;
            
            a = b;
            b = c;
        }
        return a;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {   
        int c = 0;
        Node *head = NULL;
        first = reverselist(first);
        second = reverselist(second);
        
        while(first != NULL && second != NULL)
        {   
            int n = first->data + second->data + c;
            Node *temp = new Node(n%10);
            temp->next = head;
            head = temp;
            c = n / 10;
            first = first->next;
            second = second->next;
        }
        while(first != NULL)
        {
            int n = first->data + c;
            Node *temp = new Node(n%10);
            temp->next = head;
            head = temp;
            c = n / 10;
            first = first->next;
        }
        while(second != NULL)
        {
            int n = second->data + c;
            Node *temp = new Node(n%10);
            temp->next = head;
            head = temp;
            c = n / 10;
            second = second->next;
        }
        if(c != 0)
        {
            Node *temp = new Node(c);
            temp->next = head;
            head = temp;
        }
       
        return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends