class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for(int a : asteroids){

            while(!st.empty() && st.top() > 0 && a < 0){

                if(st.top() < -a){
                    st.pop();
                    continue;
                }

                if(st.top()== -a){
                    st.pop();
                }

                a=0;
                break;
            }

            if(a!= 0){
                st.push(a);
            }
        }

        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};