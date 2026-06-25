class Solution {
public:
 vector<int>delrow={-1,0,1,0};
   vector<int>delcol={0,1,0,-1};
   bool isvalid(int & i , int & j , int & n, int & m){
        if(i<0 || i>=n) return false;
        if(j<0 || j>=m ) return false;
        return true;
    }
    void bfs( int i, int j ,vector<vector<char>>& grid, vector<vector<int>>&vis){
        int n = grid.size();
        int m = grid[0].size();
           queue<pair<int,int>>q;
           q.push({i,j});
           while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            for(int i =0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(isvalid(nrow,ncol,n,m)&& grid[nrow][ncol]=='1'&& !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
           }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
      
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                     cnt++;
                     bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};