class Solution {
    vector<int>delrow={1,0,-1,0};
    vector<int>delcol={0,-1,0,1};

    bool isvalid(int&i,int&j,int&n,int&m){
        if(i<0||i>=n)return false;
        if(j<0||j>=m)return false;
        return true;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
              if(mat[i][j]==0){
                q.push({{i,j},0});
                vis[i][j]=1;
              }
              else{
                vis[i][j]=0;
              }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int steps= it.second;
            dist[row][col]=steps;
            for(int i =0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(isvalid(nrow,ncol,n,m)&& vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }

            }
        }

        return dist;
    }
};