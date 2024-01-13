#define ll long long
class Solution {
public:
    ll dp[1001][(1 << 11)];
    vector<int> primes;
    const int mod = 1e9+7;

    ll mask(ll n){
        ll msk = 0;
        for(int i=0; i<10; i++){
            int freq = 0;
            while(n % primes[i] == 0){
                freq++;
                n /= primes[i];
            }
            if(freq > 1)
                return -1;
            if(freq == 1)
                msk |= (1 << (i+1));
        }
        return msk;
    }

    ll solve(int i, ll msk, vector<int> &nums){
        if(i >= nums.size())
            return 1;
        if(dp[i][msk] != -1)
            return dp[i][msk];
            
        ll newMask = mask(nums[i]);
        ll pick = 0, notPick = 0;

        if((newMask & msk) == 0)
            pick = solve(i+1, msk | newMask, nums);
        notPick = solve(i+1, msk, nums);

        return dp[i][msk] = (pick + notPick)%mod;
    }
    int squareFreeSubsets(vector<int>& nums) {
        primes = {2,3,5,7,11,13,17,19,23,29};
        memset(dp, -1, sizeof(dp));
        return (solve(0,1,nums)-1+mod)%mod;
    }
};