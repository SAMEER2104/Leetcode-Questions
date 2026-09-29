class Solution {
public:
    int max_square(vector<int> &heights)
    {
        int n = heights.size();

        stack<int>st;
        int ans = 0;
        int idx = 0;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                idx = st.top();
                st.pop();

                int width;

                if(!st.empty())
                    width = i - st.top() - 1;

                else
                    width = i;

                int side = min(heights[idx], width);

                ans = max(ans, side * side);
            }

            st.push(i);
        }

        while(!st.empty())
        {
            idx = st.top();
            st.pop();

            int width;

            if(!st.empty())
                width = n - st.top() - 1;

            else
                width = n;

            int side = min(heights[idx], width);

            ans = max(ans, side * side);
        }

        return ans;

    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int ans = 0;

        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>heights(col, 0);

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j] == '0')
                heights[j] = 0;

                else
                heights[j]++;
            }

            ans = max(ans, max_square(heights));
        }

        return ans;

        
        
    }
};