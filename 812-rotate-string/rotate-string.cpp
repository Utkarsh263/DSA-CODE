class Solution {
public:
    bool rotateString(string s, string goal) {
        
        // If strings are of unequal length , no rotation is possible 

        if(s.length() != goal.length()){
            return false;
        }

        string temp = s+s;

        return temp.find(goal) != string::npos;
    }
};