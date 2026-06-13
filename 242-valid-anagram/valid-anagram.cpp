class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Creating the vector array of each letter of size 26 with freq equals to zero
        vector<int>freq(26, 0);

        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }

        for(int i=0; i<t.size(); i++){
            freq[t[i] - 'a']--;
        }

        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                return false;
            }
        }

        return true;
    }
};