class Solution {
public:
vector<vector<string>>ans;

void solve(int col, int n, vector<string> & board,
vector<int>& row, vector<int> & diag1,
vector<int>& diag2) {

    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int r = 0; r < n; r++) {
        if(row[r] == 0 && diag1[r - col + n - 1] == 0&&
        diag2[r + col] == 0) {

            board[r][col] = 'Q';

            row[r] = 1;
            diag1[r - col + n - 1] = 1;
            diag2[r + col] = 1;

            solve(col + 1, n, board, row, diag1, diag2);

            board[r][col] = '.';
            row[r] = 0;
            diag1[r - col + n -1] = 0;
            diag2[r + col] = 0;
        }
    }
}

    vector<vector<string>> solveNQueens(int n) {

        ans.clear();
        vector<string>board(n, string(n, '.'));

        vector<int>row(n, 0);
        vector<int>diag1(2*n-1,0);
        vector<int>diag2(2*n-1,0);

        solve(0,n, board, row, diag1, diag2);

      

        return ans;
        
    }
};