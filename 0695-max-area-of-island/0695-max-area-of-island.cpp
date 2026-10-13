class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(int r, int c, vector<vector<int>>& grid, int& area) {
        queue<pair<int,int>> Q;
        Q.push({r, c});


        while(!Q.empty()) {
            auto[i, j] = Q.front();
            Q.pop();

            for(auto[x, y] : dir) {
                int a = x + i;
                int b = y + j;

                if(a < 0 || b < 0 || a >= grid.size() || b >= grid[0].size() || grid[a][b] == 0) continue;

                area++;
                grid[a][b] = 0;
                Q.push({a, b});
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for(int  i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int area = 1;
                    grid[i][j] = 0;
                    bfs(i, j, grid, area);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};