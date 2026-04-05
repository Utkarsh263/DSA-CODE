class Solution {
public:
    bool checkValidString(string s) {
        
        int low = 0;  // Minimum opening characters
        int high = 0; // Maximum opening characters

        for(char c : s){

            if(c == '('){
                low++;
                high++;
            }else if(c == ')'){
                low--;
                high--;  // As to balance closing bracket , opening bracket will be used 
            }else{
                low--;
                high++;
            }

            if(low < 0){
                low = 0;  // Minimum opening characters count never be negative 
            }

            if(high < 0){
                return false;  // Maximum opening character if becomes negative  => invalid 
            }
        }

        return low == 0; // Will only be true if low == 0 as all opening bracket will be balanced by closing brackets 
    }
};