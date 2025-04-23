#include<iostream>
using namespace std;

void printNumberPyramid(int n) {
    for (int row = 1; row <= n; row++) {
        for(int col=1; col<=n-row; col++) cout << " ";
        for(int col=1; col<=row; col++) cout << col;
        cout << endl;
    }
  }

int main() {
    printNumberPyramid(4);
    return 0;
}