class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(n == 0 || grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        using T = pair<int, pair<int, int>>;

        vector<pair<int, int>> dir = {
            {0, 1}, {1, 0}, {-1, 0}, {0, -1},
            {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
        };

        queue<T> Q;
        Q.push({1, {0, 0}});

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;

        while(!Q.empty()) {

            int size = Q.size();

            for(int k = 0; k < size; k++) {

                auto u = Q.front();
                Q.pop();

                int d = u.first;
                int x = u.second.first;
                int y = u.second.second;

                if(x == n-1 && y == n-1)
                    return d;

                for(auto [a, b] : dir) {

                    int i = x + a;
                    int j = y + b;

                    if(i < 0 || j < 0 || i >= n || j >= n)
                        continue;

                    if(grid[i][j] == 0 && !vis[i][j]) {
                        vis[i][j] = true;
                        Q.push({d + 1, {i, j}});
                    }
                }
            }
        }

        return -1;
    }
};