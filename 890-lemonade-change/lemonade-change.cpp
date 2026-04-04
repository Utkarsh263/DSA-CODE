class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int count5 = 0;
        int count10 = 0;

        for(int bill : bills){ 
            if(bill == 5){ // As no change is required
                count5++;
            }else if(bill == 10){ // 10 -5 = 5 needs to be returned
                if(count5 > 0){
                    count5--;
                    count10++;
                }else{
                    return false;
                }
            }else{
                if(count10 > 0 && count5 > 0){ // As 20 has been given , so 15 needs to be returned either 3*5  or 10+5
                    count10--;
                    count5--;
                }else if(count5 >= 3){
                    count5 -= 3;
                }else{
                    return false;
                }
            }
        }

        return true;

    }
};