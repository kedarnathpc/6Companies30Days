class Solution {
public:
    bool check(int i, int j, int n, vector<int>& arr){
        int prev = 0;
        for(int k = 0; k < n; k++){
            if(k >= i and k <= j)
                continue;
            if(arr[k] <= prev)
                return false;
            prev = arr[k];
        }
        return true;
    }
    
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(check(i, j, n, nums))
                    cnt++;
            }
        }

        return cnt;
    }
};