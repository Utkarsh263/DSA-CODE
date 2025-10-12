class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordSet(wordList.begin(), wordList.end());

        // if endword not in the list , no valid path
        if(wordSet.find(endWord)== wordSet.end()){
            return 0;
        }

        queue<pair<string , int>>q;
        q.push({beginWord, 1}); // {word, transformation length}

        while(!q.empty()){
            auto[words, steps] = q.front();
            q.pop();

            if(words==endWord){
                return steps;
            }

            // try changing characters
            for(int i=0; i<words.size(); i++){
                string temp= words;
                for(char ch = 'a' ; ch <= 'z'; ch++){
                    temp[i]= ch;

                    // if new word found in word set
                    if(wordSet.find(temp) != wordSet.end()){
                        q.push({temp , steps+1});
                        wordSet.erase(temp);//mark as visited
                    }
                }
            }
        }
        return 0;
    }
};