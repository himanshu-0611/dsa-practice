#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(7);
    pq.push(8);
    pq.push(2);
    pq.push(4);

    cout << pq.top(); //printing smallest ele as min heap
    


    // priority_queue<int>  pq;

    // pq.push(5);
    // pq.push(7);
    // pq.push(8);
    // pq.push(2);
    // pq.push(4);

    // cout << pq.size() << endl;

    // cout << pq.empty() << endl;

    // //top - max heap, so we will get 8
    // cout << pq.top() << endl;

    // //delete - highest ele in max heap
    // pq.pop();
    // cout << pq.top() << endl;
    return 0;
}