class Solution {
public:
    bool isPalindrome(int x) {
        
        int temp = x;

        if(x < 0){
            return false;
        }
        long long reverse = 0;

        while(x != 0){
            int digit = x % 10;
            reverse = reverse*10 + digit;
            x = x/10;
        }

        return reverse == temp;

    }
};