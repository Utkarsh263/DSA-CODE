class Solution {
public:
    int numberOfSubstrings(string s) {
        
        // Array to store count of each character
        vector<int>count(3,0);
        int left =0;
        int ans =0;
        int n = s.size();

        for(int right =0; right < n ; right++){

            // Increment the count of each character 
            count[s[right]-'a']++;

            //Make window valid 
            while(count[0] > 0 && count[1] > 0 && count[2] > 0){

                ans += (n-right);

                // start shrinking the window 
                count[s[left]-'a']--;
                left++;
            }
        }

        return ans;

    }
};