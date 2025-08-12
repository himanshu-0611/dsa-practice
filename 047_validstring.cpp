#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool checkValid(string &s, int idx, stack<char> &st) {
    cout << s << endl;
    if(s.size() == 0) {
        // cout << "s is 0" << endl;
        // cout << "st: " << st.empty() << endl;
        if(st.empty()) return true;
        return false;
    }

    st.push(s[idx]);
    s.erase(0, 1);
    char ch = 'c';
    while(!st.empty() && st.top() == ch) {
        st.pop();
        ch--;
    }
    // cout << "new s: " << s << endl;
    // cout << "st empty: " << st.empty() << endl;
    return checkValid(s, idx++, st);
}
bool isValid(string s) {
    //if len of s is odd - return false
    //stack<int> st, cmp;
    //cmp push a, b, c
    //return checkValid(&s, &0, &st)
        //if s empty
            //if st empty: return true
            //else return false;

        //st.push(s[i])
        //char ch = 'c'
        //while(st is not empty && st.top == ch):
            //st.pop
            //ch--;

        //return valid(s, idx++, st)

    stack<char> st;
    return checkValid(s, 0, st);
}

int main() {
    cout << "ans: " << isValid("abc");
    return 0;
}