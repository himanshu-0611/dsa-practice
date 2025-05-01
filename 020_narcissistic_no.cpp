#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void printV(vector<int> v) {
    cout << "\nPrinting the vector: ";
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}

//TC: n square

string isNarcissistic(int num) {
    int ch = 0, orig = num, x = num, count = 0;
    while(x) {
        count++;
        x /= 10;
    }
    while(num) {
        int pow = 1;
        for(int i=1; i<=count; i++) {
            pow *= (num%10);
        }
        ch = ch + pow;
        num /= 10;
    }
    if(ch == orig) return "Yes";
    return "No";
}

int main() {
    cout << isNarcissistic(153);
    return 0;
}