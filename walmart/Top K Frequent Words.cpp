class Solution {
public:
    static bool compare(const pair<int, string> &a, const pair<int, string> &b){
        if(a.first == b.first)
            return a.second < b.second;

        return a.first > b.first;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> v;
        unordered_map<string,int> m;
        vector<string> ans;

        for(auto &i : words){
            m[i]++;
        }

        for(auto &i : m){
            v.push_back({i.second, i.first});
        }

        sort(v.begin(), v.end(), compare);

        for(int i=0; i<k; ++i){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};