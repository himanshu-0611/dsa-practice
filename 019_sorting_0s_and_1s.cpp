#include<iostream>
#include<vector>
using namespace std;

void sorting0sAnd1s() {


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