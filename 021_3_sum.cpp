#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void printV(vector<int> v) {
    cout << "\nPrinting the vector: ";
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
}

void print2DV(vector<vector<int>> v) {
    cout << "\nPrinting 2D vector:\n";
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << endl;
    }
}

vector<vector<int>> threeSum(vector<int> &v) {
    sort(v.begin(), v.end());
    printV(v);
    vector<vector<int>> ans;
    for(int i = 0; i < v.size(); i++) {
      
        for(int j = i + 1; j < v.size(); j++) {
            for(int k = j + 1; k < v.size(); k++) {
                if(v[i] + v[j] + v[k] == 0) {
                    vector<int> s;
                    s.push_back(v[i]);
                    s.push_back(v[j]);
                    s.push_back(v[k]);
                    ans.push_back(s);
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    print2DV(threeSum(v));
    return 0;
}