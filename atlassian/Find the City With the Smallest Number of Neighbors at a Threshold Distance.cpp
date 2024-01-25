class Solution {
public:
    vector<int> bfs(int i, vector<vector<pair<int,int>>>&g, int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>dis(n,INT_MAX);
        dis[i] = 0;
        pq.push({0,i});

        while(!pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second; pq.pop();

            for(auto node : g[y]){
                if(x + node.second < dis[node.first]){
                    dis[node.first] = x + node.second;
                    pq.push({dis[node.first],node.first});
                }
            }
        }

        return dis;   
    }

    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<pair<int,int>>>g(n);
        for(auto e : edges){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        int city, temp = INT_MAX;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(auto dis : bfs(i,g,n)){
                if(dis <= th) cnt++;
            }

            if(cnt - 1 <= temp){
                temp = cnt - 1;
                city = i;
            }
        }

        return city;
    }
};