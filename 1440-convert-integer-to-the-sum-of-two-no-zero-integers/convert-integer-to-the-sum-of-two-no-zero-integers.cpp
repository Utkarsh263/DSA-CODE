class Solution {
public:
    bool isNonzero(int n){
        while(n > 0){
            if (n % 10 ==0){
                return true;
            }
            n = n/10;
            
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for (int i=1; i<n; i++){
            for (int j= i; j<n; j++){
                if((i+j == n) && (!isNonzero(i))  && (!isNonzero(j)) ){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                    
                }
                
            }
        }

        return ans;
    }
};