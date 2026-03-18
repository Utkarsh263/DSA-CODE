class Solution {
public:
    int beautySum(string s) {
        
        int n = s.size();
        int total = 0;

        for(int i = 0; i < n; i++) {
            
            vector<int> freq(26, 0);

            int maxFreq = 0;

            for(int j = i; j < n; j++) {
                
                // Expand window
                freq[s[j] - 'a']++;

                // Update max freq
                maxFreq = max(maxFreq, freq[s[j] - 'a']);

                // Find min freq (only non-zero)
                int minFreq = INT_MAX;

                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                total += (maxFreq - minFreq);
            }
        }

        return total;
    }
};