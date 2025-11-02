class Solution {
    void marked(int row,int col, vector<vector<int>>&grid){
        //up
        for(int i =row-1;i>=0;i--){
            if(grid[i][col]==1||grid[i][col]==2)
            break;
            grid[i][col]=3;
        }
        //down
        for(int i =row+1;i<grid.size();i++){
            if(grid[i][col]==1||grid[i][col]==2)
            break;
            grid[i][col]=3;
        }
        //left
        for(int i =col-1;i>=0;i++){
            if(grid[row][i]==1||grid[row][i]==2)
            break;
            grid[row][i]=3;
        }
        //right
        for(int i =col+1;i<grid[0].size();i++){
             if(grid[row][i]==1||grid[row][i]==2)
            break;
            grid[row][i]=3;
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto it : guards){
            int i = it[0];
            int j = it[1];
            grid[i][j]=1;
        }
        for(auto it:walls){
            int i = it[0];
            int j = it[1];
            grid[i][j]=2;
        }

        for(auto it:guards){
            int i =it[0];
            int j = it[1];
            marked(i,j,grid);
        }
        int cnt=0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==0)
                cnt++;
            }
        }
        return cnt;
    }
};