class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char>ST;
        unordered_map<char, char>TS;

        for(int i=0; i<s.size(); i++){

            char c1 = s[i];
            char c2 = t[i];

            // Adding violating conditions

            if(ST.count(c1) && ST[c1] != c2){
                return false;
            }

            if(TS.count(c2) && TS[c2] != c1){
                return false;
            }

            //Adding character to the map 

            ST[c1] = c2;
            TS[c2] = c1;
        }

        return true;
    }
};