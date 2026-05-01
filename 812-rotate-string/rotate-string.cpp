class Solution {
public:
    bool rotateString(string s, string goal) {
        
        // If sizes are of different sizes 
        if(s.size() != goal.size()){
            return false;
        }

        return (s+s).find(goal) != string::npos;
    }
};