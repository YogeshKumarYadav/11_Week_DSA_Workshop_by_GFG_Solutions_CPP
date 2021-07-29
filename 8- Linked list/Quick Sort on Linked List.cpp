#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function

struct node* gett(struct node *t)
{
    while(t != NULL && t->next != NULL)
        t = t->next;
    return t;    
}

struct node* split(struct node *l, struct node *r, struct node **nl, struct node **nr)
{
    struct node *piv = r, *a = NULL, *b = l, *tail = r;
    while(b != piv)
    {
        if(b->data < piv->data)
        {
            if(*nl == NULL)
                *nl = b;
        
            a = b;
            b = b->next;
        }
        else
        {
            if(a != NULL)
                a->next = b->next;
            
            struct node *temp = b->next;
            b->next = NULL;
            tail->next = b;
            tail = b;
            b = temp;
        }
    }
    
    if(*nl == NULL)
        *nl = piv;
    *nr = tail;
    
    return piv;
}

struct node* quick(struct node *l, struct node *r)
{
    if(!l || l == r)
        return l;
        
    node *nl = NULL, *nr = NULL;
    struct node *piv = split(l, r, &nl, &nr);
    
    if(nl != piv)
    {   struct node *t = nl;
        while(t->next != piv)
            t = t->next;
        t->next = NULL;
        
        nl = quick(nl, t);
        t = gett(nl);
        t->next = piv;
    }
    piv->next = quick(piv->next, nr);
    return nl;
}

void quickSort(struct node **headRef)
{
    *headRef = quick(*headRef, gett(*headRef)); 
    return;
}