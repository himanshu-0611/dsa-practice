#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;

class Node {
    public:     
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }
}; // ❗ Semicolon was missing here

// Return root node of the tree
Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return NULL;
    } else {
        Node* root = new Node(val);
        // 1 case done, rest recursion
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
}

// NLR - Preorder
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// LNR - Inorder
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// LRN - Postorder
void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
    
    if(root == NULL) {
        return;
    }

    //LOT
    queue<Node*> q;
    //initial state maintain
    q.push(root);
    //using NULL as marker
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) { // either current level all print, or next level all nodes are in queue
            //current level ki sari node print ho chuki h
            //go to next line
            cout << endl;

            //if q is empty, then do not insert NUL
            //if q non empty h, then insert NULL -> to indicate the rightmost node or end of level
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data;

            if(front->left) {
                q.push(front->left);
            }
            if(front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

int main() {
    // Sample Input: 10 20 30 -1 -1 40 -1 -1 50 -1 60 -1 -1
    Node* root = buildTree();

    cout << endl;
    cout << "Printing Preorder Traversal: " << endl;
    preOrderTraversal(root);

    cout << endl << "Printing Inorder Traversal: " << endl;
    inorderTraversal(root);

    cout << endl << "Printing Postorder Traversal: " << endl;
    postorderTraversal(root);

    cout << endl << "Level: " << endl;
    levelOrderTraversal(root);

    return 0;
}