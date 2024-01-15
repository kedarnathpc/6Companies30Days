class Solution {
public:
    bool isFriend(int x, int y){
        bool a = (y <= (x * 0.5) + 7);
        bool b = (y > x);
        bool c = (x < 100 and y > 100);

        return !(a or b or c);
    }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> m;
        int ans = 0;

        for(auto &i : ages)
            m[i]++;

        for(auto &i : m){
            for(auto &j : m){
                if(isFriend(i.first, j.first))
                    ans += i.second * (j.second - (i.first == j.first ? 1 : 0));
            }
        }

        return ans;
    }
};