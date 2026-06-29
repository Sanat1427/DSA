class Solution {
public:
#define P pair <int, pair<int,int>>

  vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, -1, 0, 1};
    
    
    bool isValid(int &row, int &col, 
                 int &n, int &m) {
                     
   
        if(row < 0 || row >= n) return false;
        if(col < 0 || col >= m) return false;
        
     
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
         int n = heights.size();
         int m = heights[0].size();
         vector<vector<int>>maxdiff(n,vector<int>(m,1e9));
         priority_queue <P, vector<P>, greater<P>> pq;
         maxdiff[0][0]=0;
         pq.push({0,{0,0}});
         while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col==m-1)
            return diff;
            for(int i =0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(isValid(nrow,ncol,n,m)){
                    int curdiff= abs(heights[nrow][ncol]-heights[row][col]);
                    if(max(curdiff,diff)<maxdiff[nrow][ncol]){
                        maxdiff[nrow][ncol]=max(curdiff,diff);
                        pq.push({maxdiff[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
         }
         return 0;
    }
};