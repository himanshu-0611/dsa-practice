#include<iostream>
using namespace std;

void printPattern(int n) {
    for(int row=1; row<=n; row++) {
        int x=row;
        for(int col=1; col<=row; col++) cout << col;
        for(int col=1; col<=(2*n - (2*row)); col++) cout << " ";
        for(int col=1; col<=row; col++) cout << row-col+1;
        cout << endl;
    }
}

int main() {
    printPattern(4);
    return 0;
}