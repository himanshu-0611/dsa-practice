#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;


int main() {
    char a[50];

    cin.getline(a, 50, '\t');
    int i = 0;
    while(a[i] != '\0') {
        if(a[i] == ' ') a[i] = 'X';
        i++;
    }

    cout << "\ncount: " << i;

    cout << "ANS: " << a;

    // char a[3];

    // cin >> a;
    // cout << a;

    // cout << "\n\nLOOP" << endl;
    // for(int i=0; i<4; i++) {
    //     cout << a[i];
    // }
    return 0;
}