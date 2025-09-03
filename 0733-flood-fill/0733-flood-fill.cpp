class Solution {
public:
 vector<int>delrow= {1,0,-1,0};
 vector<int>delcol={0,1,0,-1};
 bool isvalid(int&i,int&j,int&n,int&m){
    if(i<0||i>=n) return false;
    if(j<0||j>=m)return false;
   return true;
    
 }
 void dfs(int row, int col, int initialcolor,int newcolor, vector<vector<int>>&image,vector<vector<int>>&ans){
     ans[row][col]=newcolor;
     int n = image.size();
     int m = image[0].size();
     for(int i =0;i<4;i++){
        int nrow= row+delrow[i];
        int ncol= col+delcol[i];
        if(isvalid(nrow,ncol,n,m)&& image[nrow][ncol]==initialcolor && ans[nrow][ncol]!=newcolor){
            dfs(nrow,ncol,initialcolor,newcolor,image,ans);
        }
     }
 }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int icolor= image[sr][sc];
       vector<vector<int>>ans=image;
       dfs(sr,sc,icolor,color,image,ans);
       return ans;

    }
};