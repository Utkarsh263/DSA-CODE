class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // We will make two maps and check for mapping 

        unordered_map<char, char>sT;
        unordered_map<char , char>tS;

        if(s.length() != t.length()){
            return false;
        }

        for(int i=0; i<s.length(); i++){

            // Check s->t mapping 
            if(sT.contains(s[i]) && sT[s[i]] != t[i]){
                return false;
            }

            // check t->s mapping 
            if(tS.contains(t[i]) && tS[t[i]] != s[i]){
                return false;
            }

            // Create the mapping 
            sT[s[i]] = t[i];
            tS[t[i]] = s[i];
        }
        return true;
    }
};