class Solution {
public:
vector<int>findpsse(vector<int>arr){
    int n= arr.size();
    stack<int>st;
    vector<int>ans(n,0);
    for(int i = 0;i<=n-1;i++){
        while(!st.empty()&& arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]= !st.empty()?st.top():-1;
        st.push(i);
    }
    return ans;
}
vector<int>findnse(vector<int>arr){
    int n= arr.size();
    stack<int>st;
    vector<int>ans(n,0);
    for(int i = n-1;i>=0;i--){
        while(!st.empty()&& arr[st.top()]>arr[i]){
            st.pop();
        }
        ans[i]= !st.empty()?st.top():n;
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse = findnse(arr);
        vector<int>psse = findpsse(arr);
        int mod = 1e9+7;
        int sum=0;
        for(int i =0;i<n;i++){
            int curr = arr[i];
            int left = i-psse[i];
            int right = nse[i]-i;
            long long freq= (left*right*1ll);
            long long val = (freq*arr[i]*1ll)%mod;
            sum= (sum+val)%mod;
        }
        return sum;
    }
};