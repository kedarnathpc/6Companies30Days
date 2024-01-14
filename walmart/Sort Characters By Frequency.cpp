class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;

        for(auto &i : s)
            m[i]++;

        for(auto &i : m)
            pq.push({i.second, i.first});
        
        pair<int, char> p;
        string ans = "";
        
        while(!pq.empty()){
            p = pq.top();
            while(p.first != 0){
                ans += p.second;
                p.first--;
            }
            pq.pop();
        }   

        return ans;
    }
};