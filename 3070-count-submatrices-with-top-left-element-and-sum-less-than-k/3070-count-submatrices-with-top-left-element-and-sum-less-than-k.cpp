class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>sum(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
               sum[i][j]=grid[i][j];
               if(i>0) sum[i][j]+=sum[i-1][j];
               if(j>0)sum[i][j]+=sum[i][j-1];
               if(i>0 && j>0)sum[i][j]-=sum[i-1][j-1];
            }
        }
        int cnt=0;
        for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(sum[i][j]<=k)
            cnt++;
        }
        }
        return cnt;
    }
};