//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int NumberOFTurns(struct Node* root, int first, int second);

 // } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/
// function should return the number of turns required to go from first node to second node 
Node* LCA(Node *root, int a, int b)
{
    if(root == NULL)
        return NULL;
    if(root->data == a || root->data == b)
        return root;
    Node *left = LCA(root->left, a, b);
    Node *right = LCA(root->right, a, b);
    if(left != NULL && right != NULL)
        return root;
    if(left != NULL && right == NULL)
        return left;
    if(left == NULL && right != NULL)
        return right;
}

void turn(Node *root, int data, int &ans, int rotate, int val)
{
    if(root == NULL)
        return;
    if(root->data == data)
    {   ans += val;
        return;
    }
    if(rotate == -1)
    {
        turn(root->left, data, ans, -1, val);
        turn(root->right, data, ans, 1, val + 1);
    }
    else
    {
        turn(root->left, data, ans, -1, val + 1);
        turn(root->right, data, ans, 1, val);
    }
}

int NumberOFTurns(struct Node* root, int a, int b)
{
    if(root == NULL)
        return -1;
    Node *lca = LCA(root, a, b);
    int ans = 0;
    
    turn(lca->left, a, ans, -1, 0);
    turn(lca->left, b, ans, -1, 0);
    
    turn(lca->right, a, ans, 1, 0);
    turn(lca->right, b, ans, 1, 0);
    
    if(lca->data != a && lca->data != b)
        ans++;
    if(ans == 0)
        return -1;
    else
        return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        if ((turn = NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends