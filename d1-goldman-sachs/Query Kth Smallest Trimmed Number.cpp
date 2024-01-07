class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();

        for(auto &x : queries){
            priority_queue<pair<string,int>> vec;

            for(int i = 0; i<n; i++){
                int t= nums[i].length()-x[1];
                string p = nums[i].substr(t, x[1]);

                if(vec.size() < x[0]) vec.push({p, i});
                else{
                    if(vec.top().first > p){
                        vec.pop();
                        vec.push({p, i});
                    }
                }
            }

            int val = vec.top().second;
            ans.push_back(val);
        }

        return ans;
    }
};