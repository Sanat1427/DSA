class Solution {
public:
  vector<int>delrow={-1,0,1,0};
   vector<int>delcol={0,1,0,-1};
   bool isvalid(int & i , int & j , int & n, int & m){
        if(i<0 || i>=n) return false;
        if(j<0 || j>=m ) return false;
        return true;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i =0;i<n;i++ ){
            for(int j =0;j<m;j++){
                if((i==0 || i==n-1||j==0 || j==m-1)&&grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]=1;
                    q.push({i,j});
                    
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(int i =0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(isvalid(nrow,ncol,n,m)&&!vis[nrow][ncol]&&grid[nrow][ncol]==1){
                     vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        int cnt =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j])
                cnt++;
            }
        }
        return cnt;
    }
};