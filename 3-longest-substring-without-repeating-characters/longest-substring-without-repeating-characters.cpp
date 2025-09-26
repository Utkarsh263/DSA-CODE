class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int left = 0;
        int maxlen=0;

        for(int right=0; right<s.size(); right++){
            if(charIndex.count(s[right]) && charIndex[s[right]] >= left){
                left = charIndex[s[right]] + 1;  // move the left pointer
            }

            charIndex[s[right]] = right;
            maxlen = max(maxlen , right-left+1);
        }

        return maxlen;
    }
};