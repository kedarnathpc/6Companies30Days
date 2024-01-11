class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>dist(30, vector<long long>(30,1e15));
        for(int i = 0 ; i < original.size(); ++i){
            dist[original[i]-'a'][changed[i]-'a'] = min(dist[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
            dist[original[i]-'a'][original[i]-'a'] = 0;
            dist[changed[i]-'a'][changed[i]-'a'] = 0;
        }
        for(int k = 0; k < 26; ++k){
            for(int i = 0; i < 26; ++i){
                for(int j = 0; j < 26; ++j){
                    if(dist[i][k] == 1e15 || dist[k][j] == 1e15) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.size(); ++i){
            if(dist[source[i]-'a'][target[i]-'a'] == 1e15) return -1;
            ans += dist[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};