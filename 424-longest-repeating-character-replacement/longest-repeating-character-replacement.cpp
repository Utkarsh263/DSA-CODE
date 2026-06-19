class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //  Here we need to find out the most frequent character and subtract from window size to find replacements 
        int left = 0;
        vector<int>freq(26, 0);
        int ans = 0;
        int maxFreq = 0;

        for(int right=0; right <s.size(); right++){

            freq[s[right]-'A']++;

            maxFreq = max(maxFreq , freq[s[right]-'A']);

            while((right-left+1) - maxFreq > k){

                freq[s[left]-'A']--;
                left++;
            }

            ans = max(ans , right-left+1);
        }

        return ans;
    }
};