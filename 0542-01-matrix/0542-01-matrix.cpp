class Solution {
public:
vector<int>delRow={-1,0,1,0};
    vector<int>delCol ={0,1,0,-1};
    bool isvalid(int & i , int & j , int & n, int & m){
        if(i<0 || i>=n) return false;
        if(j<0 || j>=m ) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans=mat;
        vector<vector<int>>vis(n,vector<int>(m,0));
         queue<pair<pair<int,int>, int >>q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int step = it.second;
            ans[row][col]=step;
            for(int i =0;i<4;i++){
                int delrow = row+delRow[i];
                int delcol = col+delCol[i];
                if(isvalid(delrow,delcol,n,m)&&!vis[delrow][delcol]){
                    vis[delrow][delcol]=1;
                    q.push({{delrow,delcol},step+1});             }
            }
        }
        return ans;
    }
};