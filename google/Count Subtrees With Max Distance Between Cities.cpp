class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n-1);
        vector<vector<int>> adj(n+1);
        for(auto &a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        int m=((1<<(n+1))-1)^1;
        for(int s=m;s;s=(s-1)&m){//2^N
            if(__builtin_popcount(s)==1)
                continue;
            int b,d1;
            for(int x=1;x<=15;x++){//N
                if(((s>>x)&1)==1){
                    b=x;
                    break;
                }
            }
            int visited=0;
            int c=1;
            queue<int> q;
            visited|=(1<<b);
            q.push(b);
            while(q.size()){//N
                int f=q.front();
                d1=f;
                q.pop();
                for(auto &a:adj[f]){
                    if(((s>>a)&1)==0 or ((visited>>a)&1)==1)
                        continue;
                    visited|=(1<<a);
                    c++;
                    q.push(a);
                }
            }
            if(c!=__builtin_popcount(s))
                continue;
            c=0;
            visited=0;
            visited|=(1<<d1);
            q.push(d1);
            while(q.size()){//N
                int qlen=q.size();
                while(qlen-->0){
                    int f=q.front();
                    q.pop();
                    for(auto &a:adj[f]){
                        if(((s>>a)&1)==0 or ((visited>>a)&1)==1)
                            continue;
                        visited|=(1<<a);
                        q.push(a);
                    }
                }
                c++;
            }
            res[c-2]++;
        }
        return res;
    }
};