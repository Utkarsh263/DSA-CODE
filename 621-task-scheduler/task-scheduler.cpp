class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(char c : tasks){
            freq[c-'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());

        int countMax =0;
        for(int f : freq){
            if(f == maxFreq){
                countMax++;
            }
        }

        int partCount = maxFreq-1;
        int partLength = n+1;
        int emptySlots = partCount * partLength + countMax;

        return max((int)tasks.size(), emptySlots);
    }
};