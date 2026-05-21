class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize){
            return false;
        }
        map<int,int>mpp;
        for(int i =0;i<n;i++){
            mpp[hand[i]]++;
        }
        while(!mpp.empty()){
            int num = mpp.begin()->first;
            for(int i =0;i<groupSize;i++){
                if(mpp[num+i]==0){
                    return false;
                }
                mpp[num+i]--;
                if(mpp[num+i]<1){
                    mpp.erase(num+i);
                }
            }
            
        }
        return true;
    }
};