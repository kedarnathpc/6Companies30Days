class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        if(left.empty() && right.empty()){
            return 0;
        }else if(left.empty()){
            return n - right[0];
        }else if(right.empty()){
            return left.back();
        }
        
        return max(n-right[0], left.back());
    }
};