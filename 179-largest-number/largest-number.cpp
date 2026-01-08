class Solution {
public:
    static bool compare( string &a , string &b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        // vector to store nums
        vector<string> arr;

        for(int num : nums){
            arr.push_back(to_string(num));
        }

        // sort it using custom sort algorithm or comparator

        sort(arr.begin(), arr.end(), compare);

        if(arr[0] == "0"){
            return "0";
        }

        string result = "";

        for(string res : arr){
            result += res;
        }

        return result;
    }
};