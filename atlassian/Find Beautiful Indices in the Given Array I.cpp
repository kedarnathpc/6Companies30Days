class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> beautifulIndicesList;

        for (int i = 0; i <= static_cast<int>(s.length()) - static_cast<int>(a.length()); i++) {
            if (s.substr(i, a.length()) == a) {
                for (int j = max(0, i - k); j <= min(static_cast<int>(s.length()) - static_cast<int>(b.length()), i + k); j++) {
                    if (s.substr(j, b.length()) == b) {
                        beautifulIndicesList.push_back(i);
                        break;
                    }
                }
            }
        }

        return beautifulIndicesList;
    }
};