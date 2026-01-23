class Solution {
public:
    string reverseWords(string s) {
        string word;                    // To store each extracted word
        stringstream ss(s);             // Create stringstream from input string
        vector<string> words;           // To store all words

        while (ss >> word) {            // Extract words separated by spaces
            words.push_back(word);      // Store each word
        }

        string result;                  // Final answer string

        for (int i = words.size() - 1; i >= 0; i--) {   // Traverse words in reverse
            result += words[i];          // Add current word
            if (i > 0) result += " ";    // Add space between words (not after last)
        }

        return result;                  // Return reversed string
    }
};
