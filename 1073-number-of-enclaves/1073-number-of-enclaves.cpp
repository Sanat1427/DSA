class Solution {
public:
bool isvalid(int&i,int&j,int&n,int&m){
    if(i<0||i>=n)return false;
    if(j<0||j>=m)return false;
    return true;
}
vector<int>delrow={-1,0,1,0};
vector<int>delcol={0,1,0,-1};
void bfs(vector<vector<int>>&grid, vector<vector<bool>>&vis,queue<pair<int,int>>&q ){
    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty()){
        auto cell = q.front();
        q.pop();
        int row = cell.first;
        int col = cell.second;
        for(int i =0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol = col+delcol[i];
            if(isvalid(nrow,ncol,n,m) && grid[nrow][ncol]==1&& !vis[nrow][ncol]){
               vis[nrow][ncol]=true;
               q.push({nrow,ncol});
            }
        }
    }
}


    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
        
        if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1){
            vis[i][j]=true;
            q.push({i,j});
        }
            }
        }
          bfs(grid,vis,q);
          int count=0;
          for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j])
                count++;
            }
          }
          return count;
    }
};