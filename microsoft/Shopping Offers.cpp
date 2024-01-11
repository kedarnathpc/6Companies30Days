class Solution {
public:
    map<pair<int, vector<int>>, int> dp;

    int solve(int i, vector<int> &price, vector<vector<int>> &special, vector<int> &needs){
        // base case
        if(i == special.size()){
            int sum = 0;
            for(int i=0; i<needs.size(); ++i){
                sum += (needs[i]*price[i]);
            }
            return sum;
        }

        pair<int, vector<int>> p = {i, needs};
        
        if(dp.find(p) != dp.end())
            return dp[p];
        
        vector<int> newNeed = needs, currentOffer = special[i];
        bool flag = true;

        for(int i=0; i<needs.size(); ++i){
            if(currentOffer[i] > needs[i]){
                flag = false;
                break;
            }
        }
        
        int pick = INT_MAX, notPick = INT_MAX;

        if(flag){
            for(int i=0; i<needs.size(); ++i){
                newNeed[i] = needs[i] - currentOffer[i];
            }
            pick = currentOffer[needs.size()] + solve(i, price, special, newNeed);
        }
        notPick = solve(i+1, price, special, needs);

        return dp[p] = min(pick, notPick);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        return solve(0, price, special, needs);
    }
};