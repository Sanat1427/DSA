class Solution {
public:
vector<int>findpse(vector<int>&heights){
    int n = heights.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i =0;i<n;i++){
        while(!st.empty()&& heights[st.top()]>heights[i]){
            st.pop();
        }
    
        ans[i]= !st.empty()?st.top():-1;
            st.push(i);
    }
    return ans;
}

vector<int>findnse(vector<int>&heights){
    int n = heights.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i =n-1;i>=0;i--){
        while(!st.empty()&& heights[st.top()]>=heights[i]){
            st.pop();
        }
      
        ans[i]= !st.empty()?st.top():n;
          st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
       vector<int>nse= findnse(heights);
       vector<int>pse= findpse(heights);
       long long maxi=0;
       long long area=0;
       for(int i =0;i<n;i++){
        area= heights[i]*(nse[i]-pse[i]-1);
        maxi=max(area, maxi);
       }
        return maxi;
    }
};