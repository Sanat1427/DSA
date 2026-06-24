class Solution {
public:
     vector<int>delrow ={-1,0,1,0};
     vector<int>delcol={0,1,0,-1};
     bool isvalid(int i, int j , int n , int m){
        if(i<0 || i>=n)return false;
        if(j<0 || j>=m) return false;
        return true;
     }
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
         int m = grid[0].size();
         queue<pair<int,int>>q;
         int total=0;
         int time =0;
         for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]!=0){
                    total++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
         }
         int cnt =0;
         while(!q.empty()){
         int k = q.size();
         cnt+=k;
         while(k--){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            for(int i =0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(isvalid(nrow,ncol,n,m)){
                    if(grid[nrow][ncol]==1){
                        q.push({nrow,ncol});
                        grid[nrow][ncol]=2;
                    }
                }
            }
         }
         if(!q.empty())time++;
         }
         if(total==cnt)
         return time;
         return -1;
    }
};