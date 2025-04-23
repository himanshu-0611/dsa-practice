#include<iostream>

using namespace std;

void printSpiral(int n) {
    long long index1 = 1, row = 1, col = 1;
    int arr[n + 2][n + 2];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) arr[i][j] = -1;
    }
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) arr[i][j] = -2;
        }
    }

    string s;

    while (index1 <= n * n) {
        arr[row][col] = index1;
        if(index1 == n * n) break;
        // cout << " arr[row][col+1] " << arr[row][col+1] << endl;

        if(s == "mr") goto r;
        else if (s == "md") goto d;
        else if(s == "ml") goto l;
        else if(s == "mu") goto u;

        r: if (arr[row][col + 1] == -1 && arr[row][col + 1] != -2) {
            
            col++;
            s = "mr";
            index1++;
            continue;

        }
        d: if (arr[row + 1][col] == -1 && arr[row + 1][col] != -2) {
            row++;
            s = "md";
            index1++;
            continue;

        }
        l: if (arr[row][col - 1] == -1 && arr[row][col - 1] != -2) {
            col--;
            s = "ml";
            index1++;
            continue;

        }
        u: if (arr[row - 1][col] == -1 && arr[row - 1][col] != -2) {
            row--;
            s = "mu";
            index1++;
            continue;
        } else s = "mr";
        
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    printSpiral(4);
    return 0;
}