class Solution {
public:
    int solve(vector<int>&nums, int k){
        int cnt = 0, ans = 0, i = 0, j = 0, n = nums.size();

        while(j < n){
            if(nums[j] & 1)
                cnt++;
            
            while(cnt > k){
                if(nums[i] & 1)
                    cnt--;
                i++;
            }
            ans += (j-i+1);
            j++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};