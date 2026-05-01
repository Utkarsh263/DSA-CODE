class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()){
            return false;
        }

        vector<int>freq(26, 0);

        for(int i=0; i<s.size();i++){

            // Add character to the frequency map 
            freq[s[i]-'a']++;
        }

        for(int i=0; i<t.size();i++){
            // Decrease the frequency
            freq[t[i]-'a']--;
        }

        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                return false;
            }
        }

        return true;
    }
};