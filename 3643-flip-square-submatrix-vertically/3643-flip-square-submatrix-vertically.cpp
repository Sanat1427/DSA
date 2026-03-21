class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
       vector<vector<int>>a=grid;
        for(int row=0;row<k/2;+row++){
            for(int col=y;col<y+k;col++){
                swap(a[x+row][col],a[x+k-row-1][col]);
            }
        }
        return a;
    }
};