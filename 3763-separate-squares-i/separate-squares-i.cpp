class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18 , high = -1e18;
        double totalArea = 0.0;

        for(auto &sq : squares){
            double y = sq[1];
            double l = sq[2];
            low = min(low, y);
            high = max(high , y+l);
            totalArea += l*l;
        }

        double target = totalArea/2.0;
        
        for (int i = 0; i < 80; i++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            // 3. Calculate area below the line y = mid
            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];

                double heightBelow = min(max(mid - y, 0.0), l);
                areaBelow += heightBelow * l;
            }

            // 4. Move search space
            if (areaBelow < target)
                low = mid;     // need more area below → move line up
            else
                high = mid;    // too much area below → move line down
        }

        return low;
        
    }
};