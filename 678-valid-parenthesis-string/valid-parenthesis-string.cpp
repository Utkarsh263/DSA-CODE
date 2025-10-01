class Solution {
public:
    bool checkValidString(string s) {
        int minOpen =0;
        int maxOpen =0;
        for(char c : s){
            if(c=='('){
                minOpen++;
                maxOpen++;
            }else if(c == ')'){
                minOpen--;
                maxOpen--;
            }else{
                minOpen--;  // treat as ')'
                maxOpen++;  // treat as '('
            }

            if(minOpen < 0){
                minOpen = 0;
            }

            if(maxOpen < 0){
                return false;
            }
        }

        return minOpen == 0;
    }
};