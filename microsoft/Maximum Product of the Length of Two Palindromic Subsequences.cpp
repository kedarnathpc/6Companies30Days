class Solution {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    bool isPalindrome(string& s){
        int l=0, r = s.size()-1;
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int maxProduct(string s) {
       int n = s.size();
       unordered_map<int, int> mp;
       for(int i=1; i<(1<<n); i++){
          string t;
          for(int j=0; j<n; j++){
              if(i&(1<<j))t.push_back(s[j]);
          }
          if(isPalindrome(t)) mp[i] = t.size();
       }
       int res = 0;
       for(auto& x : mp){
           for(auto& y : mp){
             if((x.first & y.first) == 0) res = max(res, x.second* y.second);
           }
       }
       return res;
    }
};