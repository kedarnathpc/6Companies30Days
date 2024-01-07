class Solution {
public:
    vector<vector<int>> ans;

    void func(int i, vector<int> &nums, vector<int> &ds, int tar, int k){
        if(i >= nums.size()){
            if(ds.size() == k and tar == 0)
                ans.push_back(ds);
            return;
        }
        
        if(nums[i] <= tar){
            ds.push_back(nums[i]);
            func(i+1, nums, ds, tar-nums[i], k);
            ds.pop_back();
        }

        func(i+1, nums, ds, tar, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums, ds;

        for(int i = 1; i<= 9; i++){
            nums.push_back(i);
        }

        func(0, nums, ds, n, k);

        return ans;
    }
};