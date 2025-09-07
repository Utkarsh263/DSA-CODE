class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size();i++){
            char ch = s[i];
            if(ch== '(' || ch == '{' || ch == '['){ // Opening Character is there
                st.push(ch);
            }else{  // Closing Character is encountered
                if(st.empty()){
                    return false;
                }
                if((ch == ')' && st.top() != '(') || 
                (ch == '}' && st.top() != '{') 
                ||(ch == ']' && st.top() != '[')){
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};