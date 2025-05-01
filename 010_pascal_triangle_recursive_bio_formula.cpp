#include<iostream>
using namespace std;

void printPascalTriangle(int n) {
    // cout << "1" << endl; // * This is first row
    for(int row=1; row<=n; row++) { 
        int val = 1; 
        for(int col=1; col<=row; col++) {
            cout << val << " ";
            val = val * (row-col) / col;
        }
        cout << endl;
    }
}

int main() {
    printPascalTriangle(5);
    return 0;
}

// void printPascal(int n)
// {
    
// for (int line = 1; line <= n; line++)
// {
//     int C = 1; // used to represent C(line, i)
//     for (int i = 1; i <= line; i++) 
//     {
        
//         // The first value in a line is always 1
//         cout<< C<<" "; 
//         C = C * (line - i) / i; 
//     }
//     cout<<"\n";
// }
// }

// // Driver code
// int main()
// {
//     int n = 5;
//     printPascal(n);
//     return 0;
// }