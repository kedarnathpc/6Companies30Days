class Solution {
public:
const int inf = 1e9;
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>>dist(n+1, vector<int>(n+1,inf));
        for(int i = 0; i < n; ++i) dist[i][i] = 0;

        for(auto &i: edges){
            int u = i[0], v = i[1], w = i[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(dist[i][k] == inf || dist[k][j] == inf) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = -1, mn = n;
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int j = 0; j < n; ++j){
                if(dist[i][j] <= dt) cnt++;
            }
            if(cnt <= mn){
                if(cnt == mn) ans = max(ans,i);
                else ans = i;
                mn = cnt;
            }
            
        }
        return ans;
    }
};