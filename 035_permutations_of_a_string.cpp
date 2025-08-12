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

void permutation(string s, int i) {

    if(i >= s.size()) {
        cout << s << endl;
        return;
    }

    for(int j=i; j<s.size(); j++) {
        swap(s[i], s[j]);
        permutation(s, i+1);
    }
}



int main() {
    permutation("bacccc", 0);
    return 0;
}