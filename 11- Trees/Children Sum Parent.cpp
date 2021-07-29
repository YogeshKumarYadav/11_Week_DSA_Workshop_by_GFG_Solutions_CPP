#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int isSumProperty(struct Node *node);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        cout << isSumProperty(root) << "\n";

        
    }


    return 0;
}// } Driver Code Ends


/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to check whether all nodes of a tree have the value 
//equal to the sum of their child nodes.
int isSumProperty(Node *root)
{
    if(!root || !root->left && !root->right)
        return 1;
        
    if((root->left && root->right && root->data == root->left->data + root->right->data) ||
       (!root->left && root->right && root->data == root->right->data) ||
       (root->left && !root->right && root->data == root->left->data))
        return isSumProperty(root->left) && isSumProperty(root->right);
    
    return 0;    
    /*
    if(root == NULL || root->left == NULL && root->right == NULL)
        return 1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *t = q.front();
        q.pop();
        if(t->left != NULL && t->right != NULL)
        {   if(t->data == t->left->data + t->right->data)
            {   q.push(t->left);
                q.push(t->right);
            }
            else
                return 0;
        }
        else if(t->left != NULL && t->right == NULL)
            if(t->left->data == t->data)
                q.push(t->left);
            else
                return 0;
        else if(t->left == NULL && t->right != NULL)
            if(t->right->data == t->data)
                q.push(t->right);
            else
                return 0;
        else
            continue;
    }
    return 1;*/
}