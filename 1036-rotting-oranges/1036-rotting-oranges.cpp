class Solution {

public:
 vector<int>delrow={1,0,-1,0};
 vector<int>delcol={0,1,0,-1};
 bool isvalid(int&i,int&j,int&n,int&m){
    if(i<0||i>=n)return false;
    if(j<0||j>=m)return false;
    return true;
 }
 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total=0;
        int time=0;
        int cnt=0;
         queue<pair<int,int>>q;
         for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]!=0)
                total++;
                if(grid[i][j]==2)
                q.push({i,j});
            }
         }
         while(!q.empty()){
            int k = q.size();
            cnt+=k;
            while(k--){
            auto cell =q.front();
            q.pop();
        
            int row = cell.first;
            int col = cell.second;
            for(int i =0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
               if(isvalid(nrow,ncol,n,m)&&grid[nrow][ncol]==1){
                grid[nrow][ncol]=2;
                q.push({nrow,ncol});
               }

            }
         }
         if(!q.empty())
         time++;
         }
        if(total==cnt)
        return time;
        return -1;
    }
};