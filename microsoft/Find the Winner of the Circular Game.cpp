class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = i+1;
        }

        int ind = 0;
        while(v.size() > 1){
            ind = (ind+k-1)%v.size();
            v.erase(v.begin()+ind);
        }

        return v.front();
    }
};