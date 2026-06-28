class Solution {
public:
vector<int> delrow = {-1,-1,-1,0,0,1,1,1};
vector<int> delcol = {-1,0,1,-1,1,-1,0,1};
bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n) return false;
        if (col < 0 || col >= m) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        if(n==1 && m==1)return 1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if(row==n-1 && col==m-1)return dis;
            for(int i =0;i<8;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(isValid(nrow,ncol,n,m)&& grid[nrow][ncol]==0 && dist[nrow][ncol]>dis+1){
                    dist[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};