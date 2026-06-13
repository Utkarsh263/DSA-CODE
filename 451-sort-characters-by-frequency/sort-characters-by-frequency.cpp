class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char , int>freq;

        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto it : freq){
            pq.push({it.second , it.first});
        }

        // Process the heap 
        string result = "";

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