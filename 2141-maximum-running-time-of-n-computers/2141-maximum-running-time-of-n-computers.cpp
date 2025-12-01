class Solution { 
    
    typedef long long ll;

    bool possible (ll &mid,vector<int>& batteries ,int n){
        ll target = n* mid;
        for(int i =0;i<batteries.size();i++){
            target -=min((ll)batteries[i],mid);
            if(target<=0)
            return true;
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l=*min_element(begin(batteries),end(batteries));
        ll sum =0;
        for( auto it : batteries){
            sum+=it;
        }
        ll r = sum/n;
        ll result =0;
        while(l<=r){
            ll mid = (l+r)/2;
            if(possible(mid,batteries,n)){
                result = mid;
                l= mid+1;
            }
            else{
                r= mid-1;
            }
        }
        return result;
    }
};