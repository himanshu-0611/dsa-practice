#include <bits/stdc++.h>

using namespace std;

int checkFeas(vector<int> boards, int time) {
        int painter = 1, totalTime = 0;

        for(int i=0; i<boards.size(); i++) {
            if(totalTime + boards[i] <= time) {
                totalTime += boards[i];
            } else {
                painter++;
                totalTime = boards[i];
            }
        }
        return painter;
    }
    int minTime(vector<int>& boards, int k) {
        sort(boards.begin(), boards.end());
        auto it = max_element(boards.begin(), boards.end());
        int s = *it, e = accumulate(boards.begin(), boards.end(), 0), ans = -1;

        while(s <= e) {
            int mid = (s+e)/2;
            // cout << "Chceck feas for: " << mid << endl;
            int x = checkFeas(boards, mid);
            // cout << "REQ PAINTS " << x << " AND K " << k << endl;

            if(k == x) {
                // cout << "POSSIBLE ANS: " << mid << endl;
                ans = mid;
                e = mid - 1;
            } else if (x > k) {
                s = mid + 1;
            } else e = mid - 1;
        }

        return ans;
    }

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int t;
    infile >> t; // number of test cases
    while (t--) {
        int n, k;
        infile >> n >> k;
        vector<int> boards(n);
        for (int i = 0; i < n; ++i) {
            infile >> boards[i];
        }
        // TODO: Call the function to solve the problem and write the result
        int result = minTime(boards, k); // placeholder
        outfile << result << endl;
    }
    infile.close();
    outfile.close();
    return 0;
}