class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char c : num){

            while(!st.empty() && k>0 && st.top()> c){
                k--;
                st.pop();
            }

            st.push(c);
        }

        while(!st.empty() && k>0){
            k--;
            st.pop();
        }

        // string result 
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        // reverse the result as stack is LIFO data structure
        reverse(result.begin(), result.end());
        int count=0;

        int i = 0;
while (i < result.size() && result[i] == '0') {
    i++;
}
result = result.substr(i);
       

        return result.empty() ?"0" : result;
    }
};