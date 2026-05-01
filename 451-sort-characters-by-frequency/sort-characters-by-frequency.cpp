class Solution {
public:
    string frequencySort(string s) {
        
        // Hashmap 
        unordered_map<char , int>freq;

        for(char ch : s){
            freq[ch]++;
        }

        // Building max Heap 
        priority_queue<pair<int, char>>pq;

        for(auto it : freq){
            pq.push({it.second, it.first});
        }

        string result = "";
        while(!pq.empty()){

            auto top = pq.top();
            pq.pop();

            int maxFreq = top.first;
            char ch = top.second;

            result += string(maxFreq , ch);
        }

        return result;
    }
};