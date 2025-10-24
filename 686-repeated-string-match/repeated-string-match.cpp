class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s =a;
        int count=1;

        while(s.size() < b.size()){// Repeat until s is at least as long as b
            s = s+a;
            count++;
        }

        if(s.find(b) != string::npos){
            return count;  // checking for substring
        }

        s+= a;
        //Again checking for overlap
        if(s.find(b) != string::npos){
            return count+1;
        }

        return -1;
    }
};