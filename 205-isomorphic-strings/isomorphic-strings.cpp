class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char>sT;
        unordered_map<char, char>tS;

        if(s.length() != t.length()){
            return false;
        }

        for(int i=0; i<s.size(); i++){

            //check for s-> t mapping

            if(sT.count(s[i]) && sT[s[i]] != t[i]){
                return false;
            }

            // check for t->s mapping 
            if(tS.count(t[i]) && tS[t[i]] != s[i]){
                return false;
            }

            sT[s[i]] = t[i];
            tS[t[i]] = s[i];
        }

        return true;
    }
};