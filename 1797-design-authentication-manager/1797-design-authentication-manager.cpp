class AuthenticationManager {
public:
  int tl; 
  unordered_map<string,int>mpp;
    AuthenticationManager(int timeToLive) {
        tl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mpp[tokenId]=currentTime+tl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mpp.find(tokenId)!=mpp.end()){
            if(mpp[tokenId]>currentTime)
            mpp[tokenId]=currentTime+tl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt =0;
        for(auto it : mpp){
            if(it.second>currentTime)
            cnt++;

        }
         return cnt;
        }

};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */