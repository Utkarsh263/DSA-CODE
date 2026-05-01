class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // f string length differs 
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, char>sT;
        unordered_map<char, char>tS;

        for(int i=0; i<s.size(); i++){

            // check for s->t mapping

            if(sT.count(s[i]) && sT[s[i]] != t[i]){
                return false;
            }

            // check for t->s mapping
            if(tS.count(t[i]) && tS[t[i]] != s[i]){
                return false;
            }

            // Add the mapping 
            sT[s[i]] = t[i];
            tS[t[i]] = s[i];
        }

        return true;
    }
};