class Solution {
public:
    int beautySum(string s) {
        // Okk we will generate all the string and find the bauty by fixing index i and start growing from index j 

        int count = 0;
        

        

        for(int i=0; i<s.size(); i++){

            vector<int>arr(26, 0);

            for(int j=i; j<s.size(); j++){

                arr[s[j]-'a']++;

                int maxi =0;
                int mini = INT_MAX;

                for(int k=0; k<26; k++){
                    
                    if(arr[k] > 0){
                        maxi = max(maxi, arr[k]);
                        mini = min(mini , arr[k]);
                    }
                }

                count += (maxi - mini);
            }
        }

        return count;
    }
};