class Solution {
public:
    
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
          return hash1;
    }
};
    
    
    int minimumCost(vector<int>& s, vector<int>& t, vector<vector<int>>& a) {
        
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
        unordered_map<pair<int,int>,int,hash_pair> m;
        p.push({0,s[0],s[1]});
        
        m[{s[0],s[1]}]=0;
        
        int cx,cy,cz;
        
        while(!p.empty()){
            int sx = p.top()[1];
            int sy = p.top()[2];
            int c = p.top()[0];
            
            p.pop();            
            
            if(sx==t[0] && sy==t[1]) return c;            
           
            p.push({c+abs(sx-t[0])+abs(sy-t[1]), t[0], t[1]});           
            
            for(int i=0; i<a.size(); i++){
                
                if(a[i][2]==sx && a[i][3]==sy) continue;
                
                cx = abs(sx-a[i][0]);
                cy = abs(sy-a[i][1]);
                cz = a[i][4];
                
                
                if((m[{a[i][2],a[i][3]}] ==0)  || (m[{a[i][2],a[i][3]}]>c+cx+cy+cz)){
                    m[{a[i][2],a[i][3]}]=c+cx+cy+cz;
                    p.push({c+cx+cy+cz,a[i][2],a[i][3]});                    
                }
            
            } 
        }
        
        return 0;
    }
};