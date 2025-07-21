#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void insertAtBottom(stack<int> &s, int value) {
    //base case
    if(s.empty()) {
        s.push(value);
        return;
    }

    //1 case i will solve rest recursion will do
    int topValue = s.top();
    s.pop();
    //recursion
    insertAtBottom(s, value);
    //backtracking
    s.push(topValue);
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    int value = 101;
    insertAtBottom(s, value);

    //printStack
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}