class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // Map to detect characters in a window
        unordered_set<char>st;
        int left =0, right =0;
        int maxLen = 0;

        for(int right=0; right<s.size(); right++){
            
            // check if any duplicate exists 
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            maxLen = max(maxLen , right-left+1);
        }
        return maxLen;
    }
};