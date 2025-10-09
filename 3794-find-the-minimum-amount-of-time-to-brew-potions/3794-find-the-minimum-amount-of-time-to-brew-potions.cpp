class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long>done(n,0);
        for(int j=0;j<m;j++){
            done[0]+=mana[j]*skill[0];
            for(int i =1;i<n;i++){
                done[i]=max(done[i],done[i-1])+1LL*mana[j]*skill[i];
            }
            for(int i =n-1;i>0;i--){
                done[i-1]=done[i]-1LL*mana[j]*skill[i];
            }
        }
        return done[n-1];
    }
};