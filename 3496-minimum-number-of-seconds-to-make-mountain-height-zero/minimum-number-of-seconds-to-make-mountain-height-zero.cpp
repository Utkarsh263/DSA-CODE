class Solution {
public:
    
    bool canFinish(long long T, int mountainHeight, vector<int>& workerTimes){
        
        long long total = 0;
        
        for(int w : workerTimes){
            
            long long val = (2LL * T) / w;
            
            long long x = (sqrt(1 + 4*val) - 1) / 2;
            
            total += x;
            
            if(total >= mountainHeight)
                return true;
        }
        
        return false;
    }
    
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 0;
        long long right = 1e18;
        
        while(left < right){
            
            long long mid = left + (right-left)/2;
            
            if(canFinish(mid, mountainHeight, workerTimes))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};