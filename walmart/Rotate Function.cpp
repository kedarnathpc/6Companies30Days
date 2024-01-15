class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, product = 0, n = nums.size();

        for(int i = 0; i < n; ++i){
            sum += nums[i];
            product += (i*nums[i]);
        }

        int maxi = product;

        for(int i = n-1; i >= 0; --i){
            product += sum - (nums[i] * n);
            maxi = max(maxi, product);
        }

        return maxi;
    }
};