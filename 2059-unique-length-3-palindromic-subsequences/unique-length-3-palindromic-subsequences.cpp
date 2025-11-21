class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        
        // Check for each character a..z as the outer character (c _ c)
        for(char c = 'a'; c <= 'z'; c++) {
            int left = -1, right = -1;
            
            // Find first and last occurrence of character c
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == c) {
                    if(left == -1) left = i;
                    right = i;
                }
            }
            
            // If the character occurs less than twice, skip
            if(left != -1 && right != -1 && right - left > 1) {
                // Count distinct characters between left and right
                bool seen[26] = {false};
                
                for(int i = left + 1; i < right; i++) {
                    seen[s[i] - 'a'] = true;
                }
                
                ans += count(seen, seen + 26, true);
            }
        }
        
        return ans;
    }
};
