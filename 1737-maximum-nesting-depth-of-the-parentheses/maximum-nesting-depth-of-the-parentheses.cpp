class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxDepth =0;

        for(char ch : s){
            if(ch == '('){
                st.push(ch);
                maxDepth = max(maxDepth , (int)st.size());
            }else if(ch == ')'){
                st.pop();
            }else{
                continue;
            }
        }

        return maxDepth;
    }
};