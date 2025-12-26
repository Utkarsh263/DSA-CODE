class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int penalty = 0;
        // If the shop is closed for the entire day 
        for(char c : customers){
            if(c=='Y'){
                penalty++;
            }
        }

        int minPenalty = penalty;
        int besthour =0;

        // Move hours by hours 
        for(int i=0; i<n; i++){
            if(customers[i]== 'Y'){
                penalty--;  // because the shop is opened and the customer is being served
            }else{
                penalty++;
            }

            // choosing the best one 
            if(penalty < minPenalty){
                penalty = minPenalty;
                besthour = i+1;
            }
        }
        return besthour;
    }
};