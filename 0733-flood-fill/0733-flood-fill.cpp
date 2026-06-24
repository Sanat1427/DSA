class Solution {
public:
     vector<int>delrow={-1,0,1,0};
     vector<int>delcol={0,1,0,-1};
     bool isvalid(int i, int j, int n, int m){
        if(i<0 ||i>=n)return false;
        if(j<0 || j>=m) return false;
        return true;
     }
     void bfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>&ans){
         int n = image.size();
        int m = image[0].size();
      int c = image[sr][sc];
        ans[sr][sc]=color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            for(int i=0;i<4;i++){
                int nrow= row+delrow[i];
                int ncol = col+delcol[i];
                if(isvalid(nrow,ncol,n,m)&& image[nrow][ncol]==c &&  ans[nrow][ncol]!=color){
                    ans[nrow][ncol]= color;
                    q.push({nrow,ncol});

                }
            }
        }
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
        return image;

    vector<vector<int>> ans = image;
    bfs(image, sr, sc, color, ans);

    return ans;
    }
};