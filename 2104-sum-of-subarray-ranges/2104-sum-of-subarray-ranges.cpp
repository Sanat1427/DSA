class Solution {
public:
vector<int>findnge(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i =n-1;i>=0;i--){
    while(!st.empty()&& nums[st.top()]<=nums[i]){
        st.pop();

    }
    ans[i]= st.empty()?n:st.top();
    st.push(i);
    }
    return ans;
}
vector<int>findpge(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i =0;i<n;i++){
    while(!st.empty()&& nums[st.top()]<nums[i]){
        st.pop();

    }
    ans[i]= st.empty()?-1:st.top();
    st.push(i);
    }
    return ans;
}
vector<int>findnse(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i =n-1;i>=0;i--){
    while(!st.empty()&& nums[st.top()]>=nums[i]){
        st.pop();

    }
    ans[i]= st.empty()?n:st.top();
    st.push(i);
    }
    return ans;
}
vector<int>findpse(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i =0;i<n;i++){
    while(!st.empty()&& nums[st.top()]>nums[i]){
        st.pop();

    }
    ans[i]= st.empty()?-1:st.top();
    st.push(i);
    }
    return ans;
}
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge= findnge(nums);
        vector<int>pge=findpge(nums);
        vector<int>nse=findnse(nums);
        vector<int>pse=findpse(nums);
        long long a=0;
        long long b=0;
        for(int i =0;i<n;i++){
            int left = i-pge[i];
            int right = nge[i]-i;
            a+=1ll*left*right*nums[i];
        }
            for(int i =0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            b+=1ll*left*right*nums[i];
        }
        return a-b;
    }
};