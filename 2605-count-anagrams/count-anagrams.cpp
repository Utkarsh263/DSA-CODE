class Solution {
    static const int MOD = 1000000007;
    vector<long long> fact, invFact;

    long long modExp(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    void prepFactorials(int maxN) {
        fact.resize(maxN+1);
        invFact.resize(maxN+1);
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        invFact[maxN] = modExp(fact[maxN], MOD-2);
        for (int i = maxN; i > 0; i--) {
            invFact[i-1] = (invFact[i] * i) % MOD;
        }
    }

public:
    int countAnagrams(string s) {
        int n = s.size();
        prepFactorials(n);

        long long answer = 1;
        int i = 0;
        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;

            int start = i;
            while (i < n && s[i] != ' ') i++;
            int end = i; // s[start:end] is one word

            int L = end - start;
            unordered_map<char,int> freq;
            for (int j = start; j < end; j++) {
                freq[s[j]]++;
            }
            long long ways = fact[L];
            for (auto &p : freq) {
                ways = (ways * invFact[p.second]) % MOD;
            }
            answer = (answer * ways) % MOD;
        }
        return (int)answer;
    }
};
