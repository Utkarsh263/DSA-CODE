class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>count(3, 0); // for a , b , c
        int left =0;
        int ans = 0;
        int n = s.size();

        for(int right =0; right < n; right++){
            //increment the count of character
            count[s[right]-'a']++;

            // when window is valid 

            while(count[0] > 0 && count[1] > 0 && count[2]> 0){

                ans += (n-right);

                //start removing characters from the left 
                count[s[left]-'a']--;
                left++;
            }
        }

        return ans;

    }
};