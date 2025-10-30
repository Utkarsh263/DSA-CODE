class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        unordered_set<int> s(nums.begin(), nums.end());
        int longest =0;

        for(int num : s){ // Iterate over sets
            if(s.find(num-1) == s.end()){
                int current = num ;
                int streak =1;

                while(s.find(current+1) != s.end()){
                    current++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};