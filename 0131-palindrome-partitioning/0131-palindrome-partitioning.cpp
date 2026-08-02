class Solution {
public:
    bool check(string s, int left, int right){
        while(left<=right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
        }
        return true;
    }
     void func(int ind , string s , vector<string>&arr,vector<vector<string>>&ans){
        int n = s.size();
        if(ind==n){
          ans.push_back(arr);
          return;
        }
        for(int i =ind;i<n;i++){
            if(check(s,ind,i)){
                string a = s.substr(ind,i-ind+1);
                arr.push_back(a);
                func(i+1,s,arr,ans);
                arr.pop_back();
            }

        }
     }
    vector<vector<string>> partition(string s) {
        vector<string>arr;
        vector<vector<string>>ans;
        func(0,s,arr,ans);
        return ans;
    }
};