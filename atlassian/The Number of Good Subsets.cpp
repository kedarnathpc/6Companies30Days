class Solution {
    const int MOD = 1e9 + 7;
    vector<int> primes;
    vector<int> primes_to_index;

    long long power(long long a, long long b) {
        a %= MOD;
        long long res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a * 1LL) % MOD;
            }
            a = (a * a * 1LL) % MOD;
            b >>= 1;
        }
        return res;
    }

  public:
    Solution() {
        primes = vector<int>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        primes_to_index.resize(30); //see: [1]
        
        for (int i = 0; i < (int)primes.size(); i++) {
            primes_to_index[primes[i]] = i;
        }
    }
    int numberOfGoodSubsets(vector<int> &a) {
        int n = a.size();
        int bits = 10;

        vector<long long> dp(1 << bits);
        vector<int> freq(31);
        for (int x : a) {
            freq[x]++;
        }

        dp[0] = 1;
        for (int j = 2;j<=30;j++) {
            if(freq[j] == 0) continue;

            bool valid = true;
            int set = 0;
            int x = j;
            // see: [2]
            for (int prime : primes) {
                if (x % prime == 0) {
                    int count = 0;
                    while (x % prime == 0) {
                        count++;
                        x /= prime;
                    }
                    if (count == 1) {
                        set |= (1 << primes_to_index[prime]);
                    } else if (count > 1) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                continue;
            }
            // see: [3]
            for (int mask = 0; mask < (1 << bits); mask++) {
                if (dp[mask] and ((mask & set) == 0)) {
                    (dp[mask | set] += (1LL * dp[mask] * (long long)freq[j])%MOD) %= MOD;
                }
            }
        }

        long long total = 0;
        for (int mask = 1; mask < (1 << bits); mask++) {
            (total += dp[mask]) %= MOD;
        }
        // see: [4]
        (total *= power(2, freq[1])) %= MOD;
        return total;
    }
};