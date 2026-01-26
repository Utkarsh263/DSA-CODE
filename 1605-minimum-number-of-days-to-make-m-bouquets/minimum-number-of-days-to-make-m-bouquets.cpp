class Solution {
public:
    bool canMake(vector<int>&bloomDay , int m , int k , int day){
        int bouquets = 0;
        int flowers =0;

        for(int b : bloomDay){
            if(b <=day){
                flowers++;
                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            }else{
                flowers = 0;
            }
        }

        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        // Impossible case 
        if((long long)m*k > n){
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high){

            int mid = (low+high)/2;

            if(canMake(bloomDay, m,k, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};