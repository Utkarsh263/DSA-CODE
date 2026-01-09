class Solution {
public:
    bool isValid(string s) {
        // Stack operation 
        stack<char>st;

        for(char c : s){
            // For opening character case 
            if(c=='(' || c=='{' || c=='['){
                st.push(c); // push onto stack
            }else{
                if(st.empty()){
                    return false; // As only closing bracket , no opening bracket 
                }

                char top = st.top();
                st.pop();

                if((top == '('  && c != ')') ||
                    (top == '{'  && c != '}') ||
                    (top == '['  && c != ']')){

                        return false;

                }
            }
        }

        return st.empty();
        
    }
};