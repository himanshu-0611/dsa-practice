#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n > 0) {
        n = n & (n-1);
        count++;
    }
    return count;
}

int main() {
    cout << countSetBits(9);
    return 0;
}

//5=2, 6=2, 7=3, 8=1, 9=2, 10=2
// 9 & 8: 1001 & 1000 = 1000