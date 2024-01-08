class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> m;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(i+10 <= n){
                string temp = "";
                for(int j = i; j < i+10; j++){
                    temp += s[j];
                }
                m[temp]++;
            }
        }

        for(auto &i:m){
            if(i.second > 1)
                ans.push_back(i.first);
        }

        return ans;
    }
};