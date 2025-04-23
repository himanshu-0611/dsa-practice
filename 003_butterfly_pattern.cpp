#include<iostream>
using namespace std;

void printPattern(int n) {
    int max = 2*n;
    for(int row=1; row<=n*2; row++) {
        if(row<n) {
            for(int col=1; col<=row; col++) cout << "*";
            for(int col=1; col<=max-(2*row); col++) cout << " ";
            for(int col=1; col<=row; col++) cout << "*";
        } else if(row==n || row==n+1) {
            for(int col=1; col<=n*2; col++) cout << "*";
        }
        else {
            for(int col=1; col<=max-row+1; col++) cout << "*";
            for(int col=1; col<=2*(row-n-1); col++) cout << " ";
            for(int col=1; col<=max-row+1; col++) cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    // cin >> n;
    printPattern(4);
    return 0;
}