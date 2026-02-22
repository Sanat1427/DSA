class Solution {
public:
    int binaryGap(int n) {
     vector<int>a;
     for(int i =0;i<32;i++){
        if (((n >> i) & 1)) 
            a.push_back(i);
        }
     
     int ans=0;
     for(int i =0;i<a.size()-1;i++){
        ans=max(ans,a[i+1]-a[i]);
     }
     return ans;
    }
};