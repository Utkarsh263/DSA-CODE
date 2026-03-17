class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int>freq;

        for(char c : s){
            freq[c]++;
        }

        int n = s.size();

        // Create buckets 
        vector<vector<char>>bucket(n+1);

        for(auto &p : freq){
            char ch = p.first;
            int f = p.second;
            bucket[f].push_back(ch);
        }

        string result;

        for(int i=n; i>=0; i--){
            for(char c : bucket[i]){
                result += string(i, c);
            }
        }

        return result;
    }
};