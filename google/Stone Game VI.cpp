class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int n = alice.size(), a = 0, b = 0;
        vector<pair<int,int>> v;

        for(int i = 0; i < n; ++i)
            v.push_back({alice[i] + bob[i], i});
        
        sort(v.rbegin(), v.rend());

        int k = 0;
        for(auto &i : v){
            int ind = i.second;
            if(k % 2)
                b += bob[ind];
            else
                a += alice[ind];
            k++;
        }

        if(b == a)
            return 0;
        
        return a > b ? 1 : -1;
    }
};