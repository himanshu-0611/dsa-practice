#include<iostream>
#include<vector>
using namespace std;

void printPattern(vector<vector<int>> v) {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void printPascalsTriangle(int n) {
    vector<vector<int>> v;
    vector<int> t;
    t.push_back(1);
    v.push_back(t); 
    if(n == 1) {
        printPattern(v);
        return;
    }

    for(int row=1; row<n; row++) {
        vector<int> temp;
        temp.push_back(1);
        for(int i=1; i<v[row-1].size(); i++) {
            int x = v[row-1][i-1] + v[row-1][i];
            temp.push_back(x);
        }
        temp.push_back(1);
        v.push_back(temp);
    }
    printPattern(v);
    return;
}

int main() {
    printPascalsTriangle(2);
    return 0;
}


// create a vector of vector v
// push 1 & 1,1 in the v

// loop: start from 3rd row
//     define a temp vector
//     push 1 in the temp vector
//     loop: iterate the row-1 th array of vector from i=1 to i<[row-1].size()
//         int = [row-1][i-1] + [row-1][i] <- this will be ith value of our vector
//     push 1 in the temp vector
//     push temp to the v vector
        
