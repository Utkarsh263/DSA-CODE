class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>mapST;
        unordered_map<char, char>mapTS;

        if(s.length() != t.length()){
            return false;
        }

        for(int i=0; i<s.length(); i++){
            char sc= s[i];
            char tc = t[i];

            if(mapST.count(sc) && mapST[sc] != tc){
                return false;
            }

            if(mapTS.count(tc) && mapTS[tc] != sc){
                return false;
            }

            mapST[sc] = tc;
            mapTS[tc] = sc;
        }

        return true;
    }
};