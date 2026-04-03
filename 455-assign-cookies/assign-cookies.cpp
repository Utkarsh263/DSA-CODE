class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the cookies and greed factor so that greedier children get bigger cokkie in size

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size();
        int n = s.size();

        int i =0 , j =0;

        while(i<m && j<n){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }

        return i;
    }
};