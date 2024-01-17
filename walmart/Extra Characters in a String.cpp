class Solution {
public:
int dp[51];
    set<string>st;
    int memo(int i, string &s){
        if(i == s.size()) return 0;
        string str = "";
        int ans = INT_MAX;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < s.size(); ++j){
            str += s[j];
            if(st.find(str) != st.end()){
                ans = min(ans, memo(j+1,s));
            }else{
                ans = min(ans, (int)str.size() + memo(j+1,s));
            }
        }
        return dp[i] = ans;
        
    }
    int minExtraChar(string s, vector<string>& dict) {
        memset(dp,-1,sizeof(dp));
        for(string s: dict) st.insert(s);
        return memo(0,s);
    }
};