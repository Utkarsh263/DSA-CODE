class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;

        if(s.empty()){
            return;
        }

        while(left < right){
            swap(s[left++], s[right--]);
        } 
    }
};