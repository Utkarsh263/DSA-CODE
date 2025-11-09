class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a : asteroids){
            bool destroyed = false;

            while(!st.empty() && a<0 && st.top() > 0){
                if(abs(a) > st.top()){
                    st.pop(); //smaller right asteroid destroyed
                    continue; // check the next one
                }else if(abs(a) == st.top()){
                    st.pop(); // both destroyed
                }

                destroyed = true;
                break;
            }

            if(!destroyed){
                st.push(a);
            }

           
            
        }
        vector<int>result;

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};