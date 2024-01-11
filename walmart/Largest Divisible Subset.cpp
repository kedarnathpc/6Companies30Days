class Solution {
public:
    vector<int> ans, dp;
    
    void solve(vector<int> temp, int i, int prev, vector<int> &nums){
        if(i >= nums.size()){
            if(temp.size() > ans.size())
                ans = temp;
            return;
        }

        if((int)temp.size() > dp[i] and (nums[i] % prev == 0)){
            dp[i] = temp.size();
            temp.push_back(nums[i]);
            solve(temp, i+1, nums[i], nums);
            temp.pop_back();
        }

        solve(temp, i+1, prev, nums);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<=nums.size(); i++)
            dp.push_back(-1);
        
        vector<int> temp;

        solve(temp, 0, 1, nums);

        return ans;
    }
};