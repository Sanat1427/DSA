class Solution {
    private:
    bool arerulesmet(int row,int col,vector <vector<char>> &board,char digit){
        for(int i=0;i<9;i++){
            if(board[row][i]==digit) {return false;}
            if(board[i][col]==digit) {return false;}
            int startr=(row/3)*3;
            int startc=(col/3)*3;
            if(board[startr+(i/3)][startc+(i%3)]==digit){ return false;}
            }
            return true;
        }
    bool solve(vector <vector<char>> &board){
        int n=9;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                for(char digit='1';digit<='9';digit++){
                if(arerulesmet(i,j,board,digit)){
                   board[i][j]=digit;
                   if(solve(board)){
                    return true;
                   }
                   board[i][j]='.';
                }
                }
                
                return false;
                }
            }
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char> >& board) {
        solve(board);
    }
};