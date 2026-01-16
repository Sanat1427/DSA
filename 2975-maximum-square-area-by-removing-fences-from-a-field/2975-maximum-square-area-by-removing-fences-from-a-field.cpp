class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1e9+7;
      vFences.push_back(1);
      vFences.push_back(n);
      hFences.push_back(1);
      hFences.push_back(m);
      sort(vFences.begin(),vFences.end());
      sort(hFences.begin(),hFences.end());
      unordered_set<int>widths;
  
      for(int i =0;i<vFences.size();i++){
        for(int j =i+1;j<vFences.size();j++){
            int width=vFences[j]-vFences[i];
            widths.insert(width);
        }
      }
      int maxside=0;
      for(int i =0;i<hFences.size();i++){
        for(int j =i+1;j<hFences.size();j++){
            int height = hFences[j]-hFences[i];
            if(widths.find(height)!=widths.end()){
                maxside=max(maxside,height);
            }
        }
      }
      return maxside == 0 ? -1:(1LL * maxside *maxside)%mod;
    }
};