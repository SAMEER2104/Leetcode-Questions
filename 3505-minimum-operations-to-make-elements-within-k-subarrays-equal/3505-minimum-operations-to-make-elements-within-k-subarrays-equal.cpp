class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        multiset<int>left,right;
        long long sumL = 0, sumR = 0;

        vector<long long>cost(n - x + 1);

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(left.find(val));
                sumL -= val;

                right.insert(val);
                sumR += val;
            }

            while(left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.find(val));
                sumR -= val;

                left.insert(val);
                sumL += val;

            }
        };

        auto add = [&](int val) {
            if(left.empty() || val <= *left.rbegin()) {

                left.insert(val);
                sumL += val;
            } else {
                right.insert(val);
                sumR += val;

            }

            balance();

        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if( it != left.end()) {
                left.erase(it);
                sumL -= val;

            }
            else{
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }
            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * left.size() - sumL + sumR - median * right.size();

        };

        for(int i = 0;i<n;i++) {
            add(nums[i]);

            if(i >= x) {
                remove(nums[i - x]);
            }

            if(i >= x - 1) {
                cost[i - x + 1] = getCost();

            }
        }

        const long long INF = 1e18;
        vector<vector<long long >> dp( k + 1, vector<long long>( n + 1, INF));

        for(int i = 0;i<=n;i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j<=k;j++) {
            for(int i = 1; i<= n;i++) {

                dp[j][i] = dp[j][i - 1];

                if( i >= x && dp[j - 1][i - x] != INF)
                {

                    dp[j][i] = min(
                        dp[j][i], dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }
        return dp[k][n];
    }
};