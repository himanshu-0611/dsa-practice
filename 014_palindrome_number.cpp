#include<iostream>
#include<vector>
using namespace std;

string isPalindrome(int num) {
    int size = 0;
    vector<int> v;
    while(num != 0) {
        v.push_back(num%10);
        num /= 10;
    }

    cout << "v size " << v.size();

    int condition;

    if(v.size()%2 != 0) condition = (v.size()-1)/2;
    else condition = (v.size())/2;

    for(int i=0; i<condition; i++) {
        if(v[i] != v[v.size()-i-1]) {
            cout << "v[i]: " << v[i] << "\tv[x]: " << v[v.size()-i-1] << endl;
            return "No";}
    }
    return "Yes";
}

int main() {
    cout << isPalindrome(10);
    return 0;
}