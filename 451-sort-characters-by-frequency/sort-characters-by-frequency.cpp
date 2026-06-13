class Solution {
public:
    string frequencySort(string s) {
        
        // We will use hashmap to store frequency and heap for max character 

        unordered_map<char, int>freq;

        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }

        string result = "";

        // Building max heap 
        priority_queue<pair<int, char>>pq;

        for(auto it : freq){
            pq.push({it.second, it.first});
        }

        // Process the max heap till empty 
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int freq = it.first;
            char ch = it.second;

            result += string(freq, ch);
        }

        return result;
    }
};