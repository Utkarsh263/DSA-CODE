class Solution {
public:
    bool isAnagram(string s, string t) {

        // If string length are different 

        if(s.length() != t.length()){
            return false;
        }

        // Crreating the vector of size 26 freq 
        vector<int>freq(26, 0);


        //Incrementing  the frequency 
        for(int i=0; i<s.size();i++){
            freq[s[i]-'a']++;
        }

        //Decrementing the frequency from string t 
        for(int i=0; i<t.size(); i++){
            freq[t[i]-'a']--;
        }

        // Checking the validity 
        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                return false;
            }
        }

        return true;
    }
};