#include<iostream>
using namespace std;

void printZigZag(int n) {
    for(int row=1; row<=2*n+1; row++) {
        int space1, space2;
        if(row<=n+1) {
            space1 = row-1;
            space2 = 2*(n-row+1) - 1;
        } else {
            space1 = (2*n+1)-row;
            space2 = 2*(row-(n+1))-1;
        }
        

        for(int col=1; col<=space1; col++) cout << " ";
        cout << "*";
        if(row == n+1) {
            cout << endl;
            continue;
        };
        for(int col=1; col<=space2; col++) cout << " ";
        cout << "*" << endl;
    }
    cout << endl;
}

int main() {
    printZigZag(4);
    return 0;
}