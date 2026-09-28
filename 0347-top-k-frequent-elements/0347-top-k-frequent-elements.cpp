class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // We can use --> Bucekt Sort

        int n = nums.size();

        unordered_map<int, int> count_map;
        for (int num : nums)
        count_map[num]++;

        vector<vector<int>>bucket(n+1);

        vector<int>result;

        for (const auto& [num, freq] : count_map)
        bucket[freq].push_back(num);

        for(int i=n;i>=0;i--)
        {
            for(int num: bucket[i])
            {
                result.push_back(num);

                if(result.size() == k)
                return result;
            }
        }

        return result;
    }
};