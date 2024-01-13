class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int cnt = 0;

        for(auto &i : nums)
            m[i]++;

        if(k == 0){
            for(auto &i : m){
                cnt += (i.second > 1);
            }
        }
        else{
            for(auto &i : m){
                cnt += (m.find(i.first + k) != m.end());
            }
        }

        return cnt;
    }
};  