class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        deque<int> dq;
        int n = nums.size();

        int i = 0;
        int j = 0;

        while(j<n){

            while(!dq.empty() && nums[dq.back()] <= nums[j]){

                dq.pop_back();
            }
            dq.push_back(j);
            
            if(j-i+1 < k){
                j++;
            }
            else {

                while(!dq.empty() && dq.front() < i){

                    dq.pop_front();
                }
                res.push_back(nums[dq.front()]);
                i++;
                j++;
                 
            }
        }
        return res;
    }
};