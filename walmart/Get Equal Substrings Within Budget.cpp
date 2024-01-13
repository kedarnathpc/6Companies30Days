class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, ans = 0, cost = maxCost, n = s.length();

        if(s == t)
            return n;
        
        while(i < n and j < n){
            cost -= abs(s[j] - t[j]);
            if(cost < 0){
                cost += abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};