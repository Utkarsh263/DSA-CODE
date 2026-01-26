class Solution {
public:
    bool canMake(vector<int>&bloomDay , int m , int k , int day){
        int flowers =0;
        int bouquets = 0;

        for(int b : bloomDay){
            if(b <= day){
                flowers++;
                if(flowers==k){
                    bouquets++;
                    flowers= 0;
                }
            }else{
                flowers = 0; // Break the adjancency rule 
            }
        }

        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();

        // Impossible case 
        if((long long)m * k > n){
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(left <= right){
            int mid = (left + right)/2;

            if(canMake(bloomDay , m , k, mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};