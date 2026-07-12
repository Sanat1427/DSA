class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    
       vector<int>a= arr;
          int n = a.size();
      sort(arr.begin(), arr.end());
arr.erase(unique(arr.begin(), arr.end()), arr.end());
unordered_map<int,int>mpp;
for(int i =0;i<arr.size();i++){
    mpp[arr[i]]=i;
}
vector<int>ans(n);
for(int i =0;i<n;i++){
    if(mpp.find(a[i])!=mpp.end()){
        ans[i]=mpp[a[i]]+1;
    }
}

  return ans;
        
    }
};