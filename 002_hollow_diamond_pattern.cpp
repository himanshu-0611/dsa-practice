#include<iostream>
using namespace std;

void printSolidDiamond(int n) {
    int max=2*n-1;
    for(int row=1; row<=max; row++) {
        if(row <= n) {
            for(int col=1; col<=n-row; col++) cout << " ";
            for(int col=1; col<=2*row-1; col++) {
                if(col==1 || col==2*row-1) cout << "*";
                else cout << " ";
            } 
        }
        else{
            for(int col=1; col<=row-n; col++) cout << " ";
            for(int col=1; col<=(2*(max-row+1) - 1); col++) {
                if(col==1 || col==2*(max-row+1)-1) cout << "*";
                else cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    // cin >> n;
    printSolidDiamond(5);
    return 0;
}