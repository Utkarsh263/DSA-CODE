class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        // Sort the grred and cookies vector so that the greedier chid get the cookies bigger in size to get satisfied 

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0;
        int j=0;

        int m = g.size();
        int n = s.size();

        while(i<m && j<n){

            if(s[j] >= g[i]){
                i++;
            }

            j++;
        }

        return i;
    }
};