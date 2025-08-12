#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int solveUsingRecursion(int n, int x, int y) {
    //base case
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    //changing params are just one
    int ans = solveUsingRecursion(n-1, x, y) + solveUsingRecursion(n-2, x, y);
    return ans;
}

int solveUsingMem(int n, vector<int>& dp) {
    //base case
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    //step 3 (where base case finishes): check if ans already exists, if yes then return
    if(dp[n] != -1) {
        //if -1 is not here, then answer already exists
        return dp[n];
    }
    //changing params are just one
    int ans = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
    //step 2: store ans in dp array
    dp[n] = ans; //n ka answer nikala h abhi
    return dp[n];
}

int main() {
    //0 1 1 2 3 5 8 13 21
    int n = 8;
    // int ans = solveUsingRecursion(n);
    //step 1: we figured out is it 1d dp
    //create, init, pass the dp array
    vector<int> dp(n+1, -1);
    int ans = solveUsingMem(n, dp);
    cout << "Ans: " << ans << endl;
    return 0;
}