class Solution {
public:
    bool canEatAll(vector<int> &piles , int h , int k){
        long long totalHours = 0;

        for(int pile : piles){
            totalHours += (pile + k-1)/k;
        }

        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while(left <= right){
            int mid = (left + right)/2;

            if(canEatAll(piles, h , mid)){
                ans = mid;
                right = mid-1; // try least possible speed
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};