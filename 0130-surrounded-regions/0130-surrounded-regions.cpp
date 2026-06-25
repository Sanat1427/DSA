class Solution {
public:
   vector<int>delrow={-1,0,1,0};
   vector<int>delcol={0,1,0,-1};
   bool isvalid(int & i , int & j , int & n, int & m){
        if(i<0 || i>=n) return false;
        if(j<0 || j>=m ) return false;
        return true;
    }
  void dfs(int row , int col,vector<vector<char>>& board,vector<vector<int>>&vis ){
    int n = board.size();
    int m = board[0].size();
    vis[row][col]=1;
    for(int i =0;i<4;i++){
        int nrow = row+delrow[i];
        int  ncol = col+delcol[i];
        if(isvalid(nrow,ncol,n,m)&&!vis[nrow][ncol] && board[nrow][ncol]=='O'){
            dfs(nrow,ncol,board,vis);
        }
    }
  }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            //first col
            if(board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            // last col
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
            }
        }
        for(int j =0;j<m;j++){
            //first row
            if(board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
            if(board[n-1][j]=='O'){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        } 
    }
};