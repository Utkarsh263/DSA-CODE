class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if(wordSet.find(endWord)== wordSet.end()){
            return 0;
        }
        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto[words, steps] = q.front();
            q.pop();

            if(words==endWord){
                return steps;
            }

            for(int i=0; i<words.size(); i++){
                string temp= words;
                for(char ch = 'a'; ch<='z'; ch++){
                    temp[i]= ch;

                     if(wordSet.find(temp) != wordSet.end()){
                    q.push({temp, steps+1});
                    wordSet.erase(temp);
                }
                }

               
            }
        }
        return 0;
    }
};