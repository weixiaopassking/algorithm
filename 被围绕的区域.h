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

思路：
BFS，从边缘上为 “O” 的开始寻找，与它相连的肯定不能设置为 "X"
首先将与边缘连通的 "O" 改成1，表示已经访问过
剩下来的 "O"都是需要改成 "X"
然后进行修改："O"->"X" , "1"->"O"
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
