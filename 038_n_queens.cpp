class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board) {
        //need to check 3 directions
        //left horizontal
        int n = board.size();
        for(int i=0; i<=col; i++) {
            if(board[row][i] == 'Q') {
                //iska matlab same row me Q h - attack pakka
                return false;
            }
        }
        //left upper diagonal
            // x-1, y-1
            // x-2, y-2
        int i = row-1;
        int j = col-1;
        while(i >= 0 && j >= 0) { //till both are valid
            if(board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        //left lower diagonal
            // x+1, y-1
            // x+2, y-2
        int x = row+1;
        int y = col-1;
        while(x<n && y>=0) {
            if(board[x][y] == 'Q') {
                return false;
            }
            x++;
            y--;
        }
        //there is no attack possible
        return true;
    }
    //storeSolution - what if n = 3
    void storeSolution(vector<vector<char>>& board, vector<vector<string>>& ans, int n) {
        vector<string> temp;
        for(int row=0; row<n; row++) {
            string output = ""; //for each row
            for(int col=0; col<n; col++) {
                char ch = board[row][col];
                output.push_back(ch);
            }
            //ek string ready hogyi
            temp.push_back(output);
        }
        //temp ready, now put in ans
        ans.push_back(temp);
    }
    void solve(vector<vector<char>>& board, vector<vector<string>>& ans, int n, int col) {
        //base case - column out of bounds
        if(col >= n) {
            //iska matlab ans ready h
            storeSolution(board, ans, n);
            return;
        }

        //ek case hum solve karenge baaki recursion sambhal lega
        //peheli Q ko pehele col ke har ek row pr rkhke try krna
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board)) {
                board[row][col] = 'Q';
                //baaki recursion - from next col
                solve(board, ans, n, col+1);
                //backtracking - 
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        //n*n board init with . 
        vector<vector<char>> board(n, vector<char>(n, '.'));
        //start with col = 0
        int col = 0;

        solve(board, ans, n, col);
        return ans;
    }
};