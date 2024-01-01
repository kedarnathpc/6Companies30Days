class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& arr) {
        vector<string>ans;
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < arr.size(); ++i) {
            m[arr[i][0]].push_back(stoi(arr[i][1]));
        }
        for(auto &i:m){
            sort(i.second.begin(), i.second.end());
            for(int a=0; a<i.second.size(); a++){
                int cnt=1;
                for(int j=a+1; j<i.second.size(); j++){
                    if(abs(i.second[a]-i.second[j])<100) cnt++;
                }
                if(cnt>=3){
                    ans.push_back(i.first);
                    break;
                }
            }
        }
        return ans;
    }
};