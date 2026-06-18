class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int asteroid : asteroids) {

            bool destroyed = false;

            while(!st.empty() &&
                  st.top() > 0 &&
                  asteroid < 0) {

                // Current asteroid is bigger
                if(abs(asteroid) > st.top()) {
                    st.pop();
                }

                // Equal size
                else if(abs(asteroid) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                }

                // Stack asteroid is bigger
                else {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) {
                st.push(asteroid);
            }
        }

        vector<int> ans(st.size());

        for(int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};