class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long num = mass;

        for(auto &i : nums){
            if(i > num)
                return false;
            num += i;
        }

        return true;
    }
};