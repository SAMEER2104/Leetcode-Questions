class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // sort(nums.begin(),nums.end());
        // int n=nums.size()-1;
        // int ans=1;
        // for(int i=n;i>=0;i--)
        // {
        //     if(ans==k)
        //     {
        //         return nums[i];
        //     }
        //     else
        //     {
        //         ans++;
        //     }
        // }

        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i:nums)
        {
            pq.push(i);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
        
        
    
};