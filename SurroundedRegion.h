/*
将被X围住的O全部修改为X；

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 */

class Solution {
private:
    int row;
    int col;
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return ;
        row=board.size(),col=board[0].size();
        for(int i=0;i<col;++i){
            helper(board,0,i);
        }

        for(int i=0;i<row-1;++i){
            helper(board,i,0);
            helper(board,i,col-1);
        }

        for(int i=0;i<col;++i){
            helper(board,row-1,i);
        }

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='1'){
                    board[i][j]='O';
                }
            }
        }

    }

    void helper(vector<vector<char>>& board,int irow,int icol){
        if(board[irow][icol]=='O'){
            board[irow][icol]='1';

            if(irow>0){
                helper(board,irow-1,icol);
            }

            if(irow<row-1){ // down
                helper(board,irow+1,icol);
            }

            if(icol>0){
                helper(board,irow,icol-1);
            }

            if(icol<col-1){
                helper(board,irow,icol+1);
            }
        }
    }
};
