#include<iostream>
#include<vector>
using namespace std;

void sorting0sAnd1s() {
    int n; cout << "Enter the size of array: ";
    cin >> n;
    cout << "Input the array: ";
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x; cin >> x; v.push_back(x);
    }

    int left = 0, right = v.size()-1;

    while(left < right) {
        if(v[left] == 0) left++;
        else if(v[right] == 1) right--;
        else {
            swap(v[left], v[right]);
            left++;
            right--;
        }
    }

    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}

int main() {
    sorting0sAnd1s();
    return 0;
}