#include<iostream>
using namespace std;

void printSymmetricAlphabetPyramid(int n) {
    for(int row=1; row<=n; row++) {
        for(int col=1; col<=n-row; col++) cout << " ";
        for(int col=1; col<=(2*row-1); col++) {
            if(col<=((2*row-1)/2) + 1) cout << char(64+col);
            else cout << char(64+(2*row-1 - col + 1));
        }
        cout << endl;
    }
}

int main() {
    printSymmetricAlphabetPyramid(5);
    return 0;
}