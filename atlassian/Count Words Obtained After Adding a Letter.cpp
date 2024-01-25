class Solution {
public:
    int mask(string &s){
        int mask = 0;
        for(int i = 0;i<s.size();i++){
            mask = mask|(1<<(s[i] - 'a'));
        }
        return mask;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        vector<int> sMask;
		// inserting each start mask and sorting for quick searches
        for(int i = 0;i<startWords.size();i++){
            sMask.push_back(mask(startWords[i]));
        }
        int ans = 0;
        sort(sMask.begin(),sMask.end());
        for(int i = 0;i<targetWords.size();i++){
            int currMask = mask(targetWords[i]);
			// in each word unsetting one set bit and finding if it was present in start or not
            for(int i = 0;i<26;i++){
                if(currMask&(1<<i)){
                    int find = currMask&(~(1<<i));
                    if(binary_search(sMask.begin(),sMask.end(),find)){
                        ans ++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};