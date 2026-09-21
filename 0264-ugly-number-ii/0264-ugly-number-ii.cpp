class Solution {
public:
    int nthUglyNumber(int n) {

        // Implementation via Array -->

        vector<int>nums(n);
        int i2, i3, i5;

        i2 = i3 = i5 = 0;

        nums[0] = 1;

        for(int i=1;i<n;i++)
        {
            int i2Ugly = nums[i2] * 2;
            int i3Ugly = nums[i3] * 3;
            int i5Ugly = nums[i5] * 5; 

            int mn = min ({i2Ugly, i3Ugly, i5Ugly});
            nums[i] = mn;

            if(mn == i2Ugly)
            i2++;

            if(mn == i3Ugly)
            i3++;

            if(mn == i5Ugly)
            i5++;
        }

        return nums[n-1];
        
    }
};