class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        
        
        int h_cnt=1;
        int v_cnt=1;
        int max_h_cnt=1;
        int max_v_cnt=1;

        sort(h.begin(),h.end());

        for(int i=1;i<h.size();i++){
            if(h[i]==(h[i-1]+1)){
                h_cnt++;
            }
            else{
                h_cnt=1;
            }
            max_h_cnt=max(max_h_cnt,h_cnt);
        }

         sort(v.begin(),v.end());

        for(int i=1;i<v.size();i++){
            
            if((v[i])==(v[i-1]+1)){
                    v_cnt++;
            }
            else{
                v_cnt=1;
            }
             max_v_cnt=max(max_v_cnt,v_cnt);
        }
    
        h_cnt=max_h_cnt;
        v_cnt=max_v_cnt;
        
       
        if(h_cnt==v_cnt){
            return (h_cnt+1)*(v_cnt+1);
        }
        else if(h_cnt>v_cnt){
            return (v_cnt+1)*(v_cnt+1);
        }
        else{
            return (h_cnt+1)*(h_cnt+1);
        }
        
    }
};