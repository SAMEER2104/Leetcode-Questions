class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();int n = nums2.size();

        if (m > n)
        return
        findMedianSortedArrays(nums2, nums1);

        int low = 0, high = m;
        int total = m+n;
        while(low <= high){
            int cut1 = low + (high - low) / 2;
            int cut2 = (total + 1)/2 - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN:nums1[cut1-1];
            int right1 = (cut1 == m) ? INT_MAX:nums1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN:nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX:nums2[cut2];

            if (left1 <= right2 && left2 <= right1){
                if (total % 2 == 1)
                return max(left1, left2);

                return(max(left1,left2) + (double)min(right1,right2)) / 2.0;
            }
            else if (left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }

        }  
        return 0.0;      
    }
};