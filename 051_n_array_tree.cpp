#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

class Node {
    public:
    int data;
    vector<Node*> children;

    Node(int data):data(data){}
};

void preorder(Node* root) {
    if(!root) return;
    cout << root->data << " ";

    for(auto child:root->children) {
        preorder(child);
    }
}

void levelorder(Node* root) {
    if(!root) return;
    queue
}

int main() {
    Node* root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children.push_back(new Node(8));

    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    root->children[1]->children.push_back(new Node(7));
    root->children[1]->children.push_back(new Node(9));

    preorder(root);
    return 0;
}