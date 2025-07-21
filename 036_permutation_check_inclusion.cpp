#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//! gives tle

vector<string> permutation(string& s, int i, vector<string>& v) {
    vector<string> temp;

    if(i >= s.size()) {
        cout << "pushing: " << s << endl;
        v.push_back(s);
        return v;
    }

    for(int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        permutation(s, i + 1, v);
        swap(s[i], s[j]);
    }

    return v;
}
bool checkInclusion(string s1, string s2) {
    vector<string> ans;
    vector<string> v = permutation(s2, 0, ans);
    cout << "printing final v: " << endl;
    for(auto it : v) {
        if(it.find(s1) != string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "bacccc";
    cout << "included? " << checkInclusion(s1, s2);
    return 0;
}