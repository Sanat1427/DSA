class Solution {
    #define P pair <int, pair<int,int>>
    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,1,0,-1};
    bool isvalid(int&row,int&col,int&n,int&m){
        if(row<0||row>=n)return false;
        if(col<0||col>=m)return false;
        return true;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>maxdiff(n,vector<int>(m,1e9));
         priority_queue <P, vector<P>, greater<P>> pq;
         maxdiff[0][0]=0;
         pq.push({0,{0,0}});
         while(!pq.empty()){
              auto p = pq.top();
              int diff = p.first;
              int row = p.second.first;
              int col = p.second.second;
              pq.pop();
              if(row==n-1 && col==m-1)
              return diff;

              for(int i =0;i<4;i++){
                int newrow =row+delrow[i];
                int newcol = col+delcol[i];
                if(isvalid(newrow,newcol,n,m)){
                    int curdiff =  abs(heights[newrow][newcol]-heights[row][col]);
                    if(max(curdiff,diff)<maxdiff[newrow][newcol]){
                        maxdiff[newrow][newcol]=max(curdiff,diff);
                        pq.push({max(curdiff,diff),{newrow,newcol}});
                    }
                }
              }
         }
         return -1;
    }
};