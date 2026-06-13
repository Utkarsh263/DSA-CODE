class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // We will create the two maps for this mapping 
        unordered_map<char , char>sT;
        unordered_map<char , char>tS;

        if(s.length() != t.length()){
            return false;
        }

        for(int i=0; i<s.length(); i++){
            if(sT.contains(s[i]) && sT[s[i]] != t[i]){
                return false;
            }

            if(tS.contains(t[i]) && tS[t[i]] != s[i]){
                return false;
            }

            // Inserting the mapping in hashmap 
            sT[s[i]] = t[i];
            tS[t[i]] = s[i];
        }

        return true;
    }
};