#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }
};

Node* buildBST(Node* root, int value) {
    if(root == NULL) {
        root = new Node(value);
        return root;
    }
    else {
        if(value > root->data) {
            root->right = buildBST(root->right, value);
        } else {
            root->left = buildBST(root->left, value);
        }
        return root;
    }
}

Node* createBST(Node* root) {
    cout << "Enter the value for the Node: " << endl;
    int val;
    cin >> val;
    while(val != -1) {
        root = buildBST(root, val);
        cout << "\nEnter the value for the Node: " << endl;
        cin >> val;
    }
    return root;
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            //current level ki sari node travel ho gayi
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data << " ";
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
    }
}

int getMax(Node* root) {
    if(root == NULL) {
        return -1;
    }
    while(root->right != NULL) {
        root = root->right;
    }
    //now u r at rightmost node
    return root->data;
}

int getMin(Node* root) {
    if(root == NULL) {
        return -1;
    }
    //hum ek aisi node dhund rahe h jiske left me kuch nahi h
    //and we are only traversing leftwards
    while(root->left != NULL) {
        root = root->left;
    }
    //now, i am at the leftmost node
    return root->data;
}

bool searchBST(Node* root, int target) {
    if(root == NULL) {
        return false;
    }

    if(root->data == target) {
        return true;
    } else {
        //left ya right consider karna h
        if(target > root->data) {
            bool rightAns = searchBST(root->right, target);
            if(rightAns == true) {
                return true;
            }
        }
        if(target < root->data) {
            bool leftAns = searchBST(root->left, target);
            if(leftAns == true) {
                return true;
            }
        }
    }

    return false;
}



int main() {
    Node* root = NULL;
    root = createBST(root);
    cout << endl;
    cout << "Printing preorder: " << endl;
    preorder(root);
    cout << endl << "Printing inorder: " << endl;
    inorder(root);
    cout << endl << "Printing postorder: " << endl;
    postorder(root);

    cout << endl << "Prtining levelorder: " << endl;
    levelorderTraversal(root);

    cout << endl << "pringint min : " << getMin(root) << " max val " << getMax(root) << endl;

    cout << endl << "Seraching 100: Found ? - " << searchBST(root, 100);


}