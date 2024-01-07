class Solution {
public:

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<int>> heights(m, vector<int>(n, 0));

        queue<pair<int ,int>> q;


        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    isWater[i][j] = 0;
                }
                else isWater[i][j] = -1;
            }
        }

        int dr[] = {1, -1, 0, 0};
		int dc[] = {0, 0, -1, 1};
        int h = 1;
        
        while(!q.empty()) {
            
            int l = q.size();

            for (int i=0; i<l; i++) {

                auto p = q.front(); q.pop();
                int u = p.first, v = p.second;

                for (int k = 0; k<4; k++) {
                    int r = u + dr[k];
                    int c = v + dc[k];

                    if (r >= 0 && r < m && c >=0 && c < n && isWater[r][c] == -1) {
                        isWater[r][c] = h;
                        q.push({r, c});
                    }
                }
            }
            h++;
        }

        return isWater;
    }
};