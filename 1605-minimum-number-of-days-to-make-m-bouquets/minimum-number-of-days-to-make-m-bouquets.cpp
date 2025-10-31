class Solution {
public:
    bool canMakeBouquets(vector<int>&bloomDay , int m , int k , int day){
        int bouquets=0;
        int flowers =0;

        for(int bloom : bloomDay){
            if(bloom <= day){
                flowers++;
                if(flowers==k){
                    bouquets++;
                    flowers=0;
                }
            }else{
                flowers=0;
            }
        }

        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL*m*k;

        if(total > bloomDay.size()){
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;

        while(left <= right){
            int mid = (left + right)/2;

            if(canMakeBouquets(bloomDay , m , k, mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};