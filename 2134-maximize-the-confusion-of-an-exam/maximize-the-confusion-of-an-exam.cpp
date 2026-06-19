class Solution {
public:
    int solve(string &s , int k , char badChar){

        int left = 0;
        int ans = 0;
        int n = s.size();
        int badCount = 0;

        for(int right = 0; right < n; right++){

            if(s[right] == badChar){
                badCount++;
            }

            while(badCount > k){

                if(s[left] == badChar){
                    badCount--;
                }
                left++;
            }

            ans = max(ans , right-left+1);
        }

        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max(
            solve(answerKey , k, 'T'),
            solve(answerKey , k, 'F')
        );
    }
};