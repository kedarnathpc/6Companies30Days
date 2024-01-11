class Solution {
public:
    static bool comparator(const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());
        
        vector<pair<int,int>> temp = vector<pair<int,int>>(v.begin()+n-k, v.end());

        sort(temp.begin(), temp.end(), comparator);

        for(auto &i:temp)
            ans.push_back(i.first);

        return ans;
    }
};