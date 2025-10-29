class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>posn;
        vector<int> neg;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] <0){
                neg.push_back(nums[i]);
            }else{
                posn.push_back(nums[i]);
            }
        }

        int i=0;
        int j= 0;
        int k =0;

        while(i != posn.size()){
            nums[k++] = posn[i++];
            nums[k++] = neg[j++];
        }

        return nums;
    }
};