class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map <char, int> freq;

        for(char ch : sentence){
            freq[ch]++;
        }

        for(int i=0; i<26; i++){
            if(freq[i+'a']==0){
                return false;
            }
        }

        return true;
    }
};