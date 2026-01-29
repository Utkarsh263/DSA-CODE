class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.size();
        int sign = 1;
        long result =0;

        // Skip Leading Spaces 
        while(i < n && s[i] == ' '){
            i++;
        }

        // Check Sign 
        if(i<n && (s[i]=='+' ||s[i]=='-')){
            if(s[i]=='-'){
                sign = -1;
            }
            i++;
        }

        if(i<n && !isdigit(s[i])){
            return 0;
        }

        // Convert digit 
        while(i<n && isdigit(s[i])){
            result = result*10 + (s[i]-'0');

            if(sign == 1 && result > INT_MAX){
                return INT_MAX;
            }

            if(sign==-1 && -result < INT_MIN){
                return INT_MIN;
            }

            i++;
        }

        return sign*result;
    }
};