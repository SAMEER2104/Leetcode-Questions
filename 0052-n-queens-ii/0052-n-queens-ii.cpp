class Solution {
public:

int ans = 0;
void solve(int col, int n, vector<int>& row,

   vector<int>& diag1, vector<int>& diag2) {

    if(col == n) {
        ans++;
        return;
    }

    for(int r = 0; r < n; r++) {
        if(row[r] == 0 && diag1[r + col] == 0 &&
        diag2[r - col + n - 1] == 0) {

            row[r] = 1;
            diag1[r + col] = 1;
            diag2[r - col + n - 1] = 1; 

            solve(col + 1, n, row, diag1, diag2);
            row[r] = 0;
            diag1[r+col] = 0;
            diag2[r - col + n - 1] = 0;

     }
    }
   }
    int totalNQueens(int n) {

        vector<int> row(n,0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        solve(0, n ,row, diag1, diag2);

        return ans;
        
    }
};