class Solution {
public:
    unordered_set<string> st;
    bool solve(int i, string &s, vector<int> &dp){
        if(i >= s.size())
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        if(st.find(s) != st.end())
            return dp[i] = true;
        
        for(int len = 1; len <= s.size(); ++len){
            string temp = s.substr(i, len);
            if(st.find(temp) != st.end() and solve(i + len, s, dp))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, -1);

        for(auto &i : wordDict)
            st.insert(i);
        
        return solve(0, s, dp);
    }
};