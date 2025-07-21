#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void printV(vector<int> v) {
    cout << "\nPrinting the vector: ---------- ";
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}

void print2DV(vector<vector<int>> v) {
    cout << "\nPrinting 2D vector: --------- ";
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << endl;
    }
}

void reverseQueue(queue<int> &q) {
    //push all element of q into stack
    stack<int> s;
    while(!q.empty()) {
        int e = q.front();
        q.pop();
        s.push(e);
    }
    while(!s.empty()) {
        int e = s.top();
        s.pop();
        q.push(e);
    }
    //push all element of stack into q
}

void pringQueue(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverseQUsingRecusrion(queue<int> &q) {
    //base case
    if(q.empty()) {
        return;
    }
    //1 case me karunga baki recursion karega
    int e = q.front();
    q.pop();
    //baaki recursion
    reverseQUsingRecusrion(q);
    q.push(e);
}

//unusedElementCount = q ka size init
void reverseInKGrp(queue<int> q, int k, int unusedElementCount) {

    //let's find out whether we have any
    //k ele to reverse or not

    if(unusedElementCount >= k) {
        //i have k grp to reverse
        //reverse it
        //1 case main solve karunga
        stack<int> s;
        for(int i=0; i<k; i++) {
            int e = q.front();
            q.pop();
            s.push(e);
        }
        for(int i=0; i<k; i++) {
            int e = s.top();
            s.pop();
            q.push(e);
        }
        //baaki recursion sambhal lega
        reverseInKGrp(q,k,unusedElementCount-k);
    } else {
        //i dont have k grp to reverse
        //as it is ee ko push krna tha
        while(unusedElementCount--) {
            int e = q.front();
            q.pop();
            q.push(e);
        }
    }
}  

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);
    pringQueue(q);
    return 0;
}