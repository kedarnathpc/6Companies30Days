class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int median = n%2 ? nums[n/2] : (nums[n/2] + nums[(n-1)/2])/2;
        int ans = 0;

        for(auto &i:nums) ans += abs(i - median);

        return ans;
    }
};