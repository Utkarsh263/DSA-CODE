class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int>freq(26,0);

        // Storing frequency of each character 

        for(char c : s){

            freq[c-'a']++;
        }

        for(char c : t){

            freq[c-'a']--;
        }

        for(int i=0; i<25; i++){

            if(freq[i] != 0){
                return false;
            }
        }

        return true;
    }
};