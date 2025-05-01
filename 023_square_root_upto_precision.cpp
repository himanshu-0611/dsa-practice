#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include <iomanip>

using namespace std;

// in what case ans = -1 will be returned
float find_square_root_upto_precision(float n, int precision) {
    float s = 0, e = n, ans;
    
    while(s <= e) {
        long long mid = s + (e-s)/2;

        if(mid * mid == n) return mid;
        else if(mid * mid > n) e = mid - 1;
        else {
            ans = mid;
            s = mid + 1;
        }
    }
    float factor = 1, p = ans;
    for(float i=1; i <= precision; i++) {
        factor /= 10;
        float j = 1;
        float check = ans;
        while(j <= 9) {
            check = check + factor;
            // cout << "check: " << check << endl;
            if(check * check <= n) {
                // cout << "possibility: " << p << " for factor: " << factor << endl;
                p = check;
            }
            else break;
            j++;
        }
        ans = p;
    }

    return ans;
}

int main() {
    cout << "\nans: " << setprecision(6) << find_square_root_upto_precision(68, 4);
    return 0;
}