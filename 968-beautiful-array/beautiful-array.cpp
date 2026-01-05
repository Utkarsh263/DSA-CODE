class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> result;
        if(n==1){
            return {1};
        }

        vector<int>odd = beautifulArray((n+1)/2);
        vector<int>even = beautifulArray(n/2);

        // Constructing odd array now 
        for(int x : odd){
            result.push_back(2*x-1);
        }

        //Costructing even array now 
        for(int x : even){
            result.push_back(2*x);
        }

        return result;

    }
   

};