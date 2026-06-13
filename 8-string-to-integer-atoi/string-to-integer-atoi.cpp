class Solution {
public:
    int myAtoi(string s) {
        
        int i=0;
        int n = s.size();
        long long result = 0;
        int sign = 1;

        while(i<n && s[i] == ' '){
            i++;
        }

        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }

        while(i<n && isdigit(s[i])){

            int digit = s[i] -'0';
            result = (result*10)+digit;

            if(sign * result < INT_MIN){
                return INT_MIN;
            }

            if(sign * result > INT_MAX){
                return INT_MAX;
            }
            i++;
        }

        return sign*result;
    }
};