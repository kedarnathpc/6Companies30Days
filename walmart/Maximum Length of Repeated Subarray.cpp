class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        vector<int> prev(1001, 0), curr(1001, 0);
        
        for(int i=1; i<=nums1.size(); i++){
            for(int j=1; j<=nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = 0;
                ans = max(ans, curr[j]);
            }
            prev = curr;
        }

        return ans;
    }
};