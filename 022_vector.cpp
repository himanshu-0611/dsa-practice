#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void printV(vector<int> v) {
    cout << "\nPrinting the vector: ";
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}

void print2DV(vector<vector<int>> v) {
    cout << "\nPrinting 2D vector:";
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> m;
    m.push_back(10);
    m.push_back(20);
    m.push_back(30);
    m.insert(m.begin()+10, 50);
    printV(m);
    return 0;
}