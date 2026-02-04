class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(int a : asteroids){
            if(a>0){
                st.push(a);
            }else{
                bool destroyed = false;
                while(!st.empty() && st.top() >0){
                    if(st.top() > -a){
                        destroyed = true;
                        break;
                    }else if(st.top()==-a){
                        st.pop();
                        destroyed = true;
                        break;
                    }else{
                        st.pop();
                    }
                }

                if(!destroyed){
                    st.push(a);
                }
            }
        }

        vector<int>ans(st.size());
        for(int i= st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};