#include<iostream>
using namespace std;

//time: o(n^3)
//space: o(1)

long int getFactorial(int n) {
    if(n>=1) return n*getFactorial(n-1);
    else return 1;
}

void printPascalTriangle(int n) {
    for(int row=0; row<n; row++) {
        for(int col=0; col<=row; col++) {
            cout << getFactorial(row)/(getFactorial(row-col) * getFactorial(col)) << " ";
        }
        cout << endl;
    }
}

int main() {
    printPascalTriangle(7);
    return 0;
}