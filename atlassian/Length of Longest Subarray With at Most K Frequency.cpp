class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 1;
        int start = 0;
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); ++i) {
            if (d.find(nums[i]) == d.end()) {
                d[nums[i]] = 1;
            } else {
                d[nums[i]] += 1;
                if (d[nums[i]] > k) {
                    while (nums[start] != nums[i]) {
                        d[nums[start]] -= 1;
                        start += 1;
                    }
                    start += 1;
                    d[nums[i]] -= 1;
                }
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};