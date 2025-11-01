class Solution {
public:
    bool canShip(vector<int>&weights, int days, int capacity){
        int currLoad =0;
        int dayNeeded=1;
        for(int w: weights){
            if(currLoad +w > capacity){
                dayNeeded++;
                currLoad=0;
            }
            currLoad += w;
        }

        return dayNeeded <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high){
            int mid = (low + high )/2;

            if(canShip(weights, days,mid)){
                high = mid; // try even smaller 
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};





// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maximum(vector<int> &weights){
//         int n = weights.size();
//         int maxi = INT_MIN;
//         for(int i=0; i<n; i++){
//             maxi =max(maxi, weights[i]);
//         }

//         return maxi;
//     }

//     int numberDays(vector<int> &weights, int cap){
//         int load=0;
//         int days=1;
//         int n = weights.size();

//         for(int i=0; i<n; i++){
//             if(weights[i]+load >cap){
//                 days += 1;
//                 load = weights[i];
//             }else{
//                 load += weights[i];
//             }
//         }
//         return days;
//     }
//     int shipWithinDays(vector<int>& weights, int days) {
//         int low = maximum(weights);
//         int n = weights.size();
//         int high = accumulate(weights.begin(), weights.end(), 0);


//         while(low <= high){
//             int mid = (low+high)/2;

//             if(numberDays(weights, mid)<= days){
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }

//         return low;
//     }
// };