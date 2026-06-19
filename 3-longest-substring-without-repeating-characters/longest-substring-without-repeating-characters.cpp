class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // Hashset to store unique character 
        unordered_set<char>st;
        int left = 0;
        int right = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++){

            while(st.find(s[right]) != st.end()){
                st.erase(s[left++]);
            }

            st.insert(s[right]);

            maxLen = max(maxLen , right-left+1);
        }

        return maxLen;
    }
};