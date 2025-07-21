#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //Constructor
        Node(int value) {
            this->data = value;
            this->next = NULL;
        }
};

//return head of the updated LL
void InsertAtHead(int value, Node* &head, Node* &tail) {

    //empty LL
    if(head == NULL && tail == NULL) {
        //step 1: create a new node
        Node* newNode = new Node(value);
        //step 2: point head and tail no that new node
        head = newNode;
        tail = newNode;
    }
    //non empty LL
    else {
        //step 1: create a new node
        Node* newNode = new Node(value);
        //step 2: link the new node to the original LL
        newNode->next = head;
        //step 3: udpate the head to the first node
        head = newNode;
    }

    //return head of the LL
    // return head;
}

void InsertAtTail(int value, Node* &head, Node* &tail) {

    //empty LL
    if(head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    //non empty LL
    else {
        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }

    // return head;
}

void PrintLL(Node* head) {
    
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << " -------------- " << endl;
}

bool SearchLL(Node* head, int target) {

    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == target) return true;
        temp = temp->next;
    }

    return false;
}

int lengthOfLL(Node* head) {

    Node* temp = head;

    int len = 0;

    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    
    return len;
}

void insertAtPosition(int pos, int value, Node* head, Node* tail) {

    //if we want to insert at pos 3
    //s1: create a node
    //s2: reach at pos pos-1 - move temp ahead pos-2 times
    //s3: newNode->next = temp->next
    //s4: temp->next = newNode
    //if pos == 1: insertAtHead
    //if pos == len+1: insertAtTail

    //assuming given pos will not be invalid

    int length = lengthOfLL(head);
    //valid range 1 to len+1
    if(pos < 1 || pos > length+1) {
        cout << "\npos value is ofb" << endl;
        return;
    }

    if(pos == 1) {
        InsertAtHead(value, head, tail);
        return;
    } 
    if(pos == length+1) {

        InsertAtTail(value, head, tail);
    }

    else {

        //middle ki position h koi
        //s1: node create
        Node* newNode = new Node(value);
        //s2: temp var to pos-1 reach karaya tha
        Node* temp = head;
        for(int i=1; i<=pos-2; i++) {
            temp = temp->next;
        }
        //s3: newNode to temp->next se connect kiya tha
        newNode->next = temp->next;
        //s4: temp ko newNode se connect kiya
        temp->next = newNode;
    }
    
}

void deleteFromPos(int pos, Node* &head, Node* &tail) {

    //invalid cases
    int len = lengthOfLL(head);

    if(pos > len) {
        return;
    }
    if(head == NULL && tail == NULL) {
        return;
    }
    //pos = 1 and LL single node
    if(head == tail && pos == 1) {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    //LL has multple nodes but pos = 1
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else {
        //either deleting middle or last node

        //s1: setup cur, prev, forward
        // Node* previous = head;
        // for(int i=1; i<=pos-2; i++) {
        //     previous = previous->next;
        // }
        // Node* current = previous -> next;
        // Node* forward = current -> next;

        // //update links
        // current->next = NULL;
        // previous->next = forward;
        // //current is isolated now
        // delete current;

        Node* prev = head;
        for(int i=1; i<=pos-2; i++) {
            prev = prev->next;
        }
        Node* curr = prev->next;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void reverseLL(Node* head) {

    //empty LL
    if(head == NULL) {
        return;
    }

    //setting up prev and curr
    Node* prev = NULL;
    Node* curr = head;

    //updating links
    while(curr != NULL) {

        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    //update head
    head = prev;
}

Node* reverseLLRecursive(Node* &curr, Node* &prev) {

    //return the head of reversed LL
    if(curr == NULL) { // means LL is reversed, so on head its prev
        return prev;
    }

    //1 case i will solve
    // Node* curr = head; //gaurantee that curr is non null as its head
    Node* forward = curr->next;

    curr->next = prev;
    //till now i have reversed one renode, rest recursion will do
    
    return reverseLLRecursive(forward, curr);
}

Node* getMidNode(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool checkPalindrome(Node* head) {
    //find len of ll
    int len = lengthOfLL(head);
    //find mid
    Node* mid = getMidNode(head);
    //update mid as per even/odd len
    //even len mid as it is
    Node* finalMid = NULL;
    if(len & 1) {
        //odd
        finalMid = mid->next;
    } else {
        finalMid = mid;
    }
    //reversell startfrom mid noe
    reverseLL(finalMid);
    //now i have 2 LL with starting pointer as head and finalMid

    //compare and return t/false
    Node* temp = head;
    while(temp != NULL && finalMid != NULL) {

        if(temp->data != finalMid->data) return false;
        //ek ek step aage badhao
        temp = temp->next;
        finalMid = finalMid->next;
    }
    //if till here then all data matched, means palindrom
    return true;
}

int main() {
    //Empty LL
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(10, head, tail);
    InsertAtHead(20, head, tail);
    InsertAtHead(30, head, tail);
    InsertAtTail(60, head, tail);
    PrintLL(head);
    // cout << "data found: " << SearchLL(head, 0);
    // cout << "\ntotallen: " << lengthOfLL(head);
    // insertAtPosition(2, 100, head, tail);
    // cout << endl;
    // PrintLL(head);

    // cout << "Starting deletion" << endl;
    // PrintLL(head);
    // cout << endl;
    // deleteFromPos(5, head, tail);
    // PrintLL(head);

    // reverseLL(head);
    Node* prev = NULL;
    head = reverseLLRecursive(head, prev);
    PrintLL(head);
    cout << endl << "MID NODE: " << getMidNode(head)->data;

    return 0;
}