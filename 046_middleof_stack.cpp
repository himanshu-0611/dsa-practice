#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
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

// void printMiddleFromStack(stack<int> &s, int count, int ts) {
//     if(count == ts/2) {
//         cout << s.top();
//         return;
//     }

//     int value = s.top();
//     s.pop();
//     count++;
//     printMiddleFromStack(s, count, ts);
// }

bool checkSorted(stack<int>& s, int prev) {
    //base case
    if(s.empty()) {
        return true;
    }

    //1 case me solve karega and baaki recursion sambhalega
    int next = s.top();
    if(next < prev) {
        return false;
    } else {
        //next >= prev
        //move prev
        prev = next;
        //pop 
        s.pop();
        return checkSorted(s, prev);
    }
}

void insertSorted(stack<int> &s, int value) {

    //base case
    if(s.empty()) {
        s.push(value);
        return;
    }

    if(value <= s.top()) {
        s.push(value);
        return;
    } else {
        //value > s top
        int topValue = s.top();
        s.pop();
        //recursion
        insertSorted(s, value);
        //backtrack
        s.push(topValue);
    }
}

int main() {
    cout << functionName();
    return 0;
}