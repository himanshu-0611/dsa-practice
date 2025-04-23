#include<iostream>
using namespace std;

void printHourglass(int n) {
    for(int row=1; row<=n*2; row++) {
        int space, stars;
        if(row<=n) {
            space = row-1;
            stars = 2*(n-row+1);
        } else {
            space = n*2-row;
            stars = 2*(row-n);
        }
        for(int col=1; col<=space; col++) cout << " ";
        for(int col=1; col<=stars; col++) cout << "* ";
        cout << endl;
    }
}

int main() {
    printHourglass(4);
    return 0;
}