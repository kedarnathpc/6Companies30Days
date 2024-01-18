class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int,pair<int,int>> m;

        for(int i = 0; i < n; ++i){
            m[matches[i][0]].first++;
            m[matches[i][1]].second++;
        }

        vector<int> arr,brr;

        for(auto &i : m){
            if(i.second.second == 0)
                arr.push_back(i.first);
            if(i.second.second == 1)
                brr.push_back(i.first);
        }

        return {arr, brr};
    }
};