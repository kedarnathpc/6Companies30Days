class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> sf, gf;
        int n = guess.size();
        int bulls = 0;
        
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i])
                bulls++;
            else{
                sf[secret[i]]++;
                gf[guess[i]]++;
            }
        }

        int cows = 0;
        
        for(auto &i:gf){
            cows += min(i.second, sf[i.first]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};