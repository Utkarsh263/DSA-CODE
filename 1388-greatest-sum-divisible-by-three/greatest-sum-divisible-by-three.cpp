class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        // store smallest few numbers of mod1 and mod2
        vector<int> mod1, mod2;

        for (int num : nums) {
            sum += num;
            if (num % 3 == 1) mod1.push_back(num);
            else if (num % 3 == 2) mod2.push_back(num);
        }

        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if (sum % 3 == 0) return sum;

        int ans = 0;
        if (sum % 3 == 1) {
            // remove smallest mod1
            int remove1 = INT_MAX;
            if (!mod1.empty()) remove1 = mod1[0];
            
            // remove two smallest mod2
            int remove2 = INT_MAX;
            if (mod2.size() >= 2) remove2 = mod2[0] + mod2[1];

            ans = sum - min(remove1, remove2);
        } 
        else { // sum % 3 == 2
            // remove smallest mod2
            int remove1 = INT_MAX;
            if (!mod2.empty()) remove1 = mod2[0];

            // remove two smallest mod1
            int remove2 = INT_MAX;
            if (mod1.size() >= 2) remove2 = mod1[0] + mod1[1];

            ans = sum - min(remove1, remove2);
        }

        return ans < 0 ? 0 : ans;
    }
};
