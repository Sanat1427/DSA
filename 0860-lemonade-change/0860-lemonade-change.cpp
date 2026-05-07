class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
       
        int fives=0;
        int tens =0;
        for(int i =0;i<n;i++){
            if(bills[i]==5){
                fives++;
            }
            if(bills[i]==10){
                if(fives>=1){
                    fives--;
                    tens++;
                }
                else{
                    return false;
                    break;
                }
            }
            if(bills[i]==20){
                if(fives>=1 && tens>=1){
                    fives--;
                    tens--;
                }
                else if(fives>=3){
                    fives-=3;
                }
                else{
                    return false;
                    break;
                }
            }
        }
        return true;
    }
};