#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

#include<limits.h>

long long int solve(long long int dividend, long long int divisor) {
    long long int s = 0;
    long long int e = dividend;
    long long int ans = -1;

    while(s<=e) {
        long long int mid = s + ((e-s) >> 1);
        cout << "s is :" << s << "\nmid is : " << mid << "\ne is : " << e << endl << endl;

        long long int product = divisor*mid;

        if(product == dividend) return mid;
        else if(product > dividend) e = mid - 1;
        else {
            ans = (long long int) mid;
            //right
            s = mid + 1;
        }
    }
    cout << "ans b4 returning: " << ans << endl;
    return ans;
}
long long int findQuotient(int dividend, int divisor) {
    if(divisor == 0) {
        return INT_MAX;
    }
    // else if (dividend == INT_MIN && divisor == -1) {
    //     // cout << "returning " << (long long int) INT_MAX + 1 << cout;
    //     return (long long int) INT_MAX +1;
    // }
    long long int ans = solve(abs((long long int) dividend), abs((long long int) divisor));

    cout << "ans is: " << ans << endl;

    if(dividend>0 && divisor > 0 || (dividend < 0 && divisor < 0)) return (long long int) ans;
    else return (long long int) (0-ans);
}

int main() {
    cout << findQuotient(-2147483648, -1);
    return 0;
}