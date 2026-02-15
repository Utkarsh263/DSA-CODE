class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.size() - 1;   // pointer for a (last index)
        int j = b.size() - 1;   // pointer for b (last index)
        int carry = 0;          // carry for addition
        
        string ans = "";

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // add from string a
            if(i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // add from string b
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // current bit
            ans += (sum % 2) + '0';

            // update carry
            carry = sum / 2;
        }

        // reverse because we added from back
        reverse(ans.begin(), ans.end());
        return ans;
    }
};