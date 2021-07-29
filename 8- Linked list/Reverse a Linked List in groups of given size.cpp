#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL || k == 1)
            return head;
        
        node *ref = new node(0);
        ref->next = head;
        node *a = ref, *b = ref, *c = ref, *t = head;
        int n = 0;
        
        while(t->next != NULL)
        {   t = t->next;
            n++;
        }
        while(n > 0)
        {   b = a->next;
            c = b->next;
            int i;
            if(n >= k)
                i = 1;
            else
                i = k - n;
            while(i < k)
            {
                b->next = c->next;
                c->next = a->next;
                a->next = c;
                c = b->next;
                i++;
            }
            a = b;
            n -= k;
        }
        return ref->next;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends