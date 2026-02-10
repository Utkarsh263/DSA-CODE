class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);

        for(char t: tasks){
            freq[t-'A']++;
        }

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];
        int countMax = 1;

        for(int i=24; i>=0; i--){
            if(freq[i]==maxFreq){
                countMax++;
            }else{
                break;;
            }
        }

        int formula = (maxFreq-1)*(n+1) + countMax;

        return max((int)tasks.size(), formula);
    }
};