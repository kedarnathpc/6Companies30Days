class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1e9+7;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while(k--){
            int a = pq.top();
            pq.pop();
            pq.push(++a);
        }   

        long long ans = 1;

        while(!pq.empty()){
            ans = (ans * pq.top())%mod;
            pq.pop();
        }

        return ans%mod;
    }
};