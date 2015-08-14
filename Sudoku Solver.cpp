/*Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. */
//思路：一共81个位置，每插入一个数，就验证一下这个数是否valid，如果试遍了1-9所有得数，都没有正确的
//那么就回溯到前一个位置，不断地尝试，回溯直到到达第81个位置
//难点是回溯的函数和检验valid这个函数怎么写
class Solution {
public:
    bool check(vector<vector<char>>& board,int pos)
    {
        int row=pos/9;
        int col=pos%9;
        char tp=board[row][col];
        for(int i=0;i<9;i++)//the row
        {
            if(i!=col)
            {
                if(board[row][i]==tp)
                    return false;
            }
        }
        for(int i=0;i<9;i++)//the col
        {
            if(i!=row)
            {
                if(board[i][col]==tp)
                    return false;
            }
        }
        int br=row/3*3;
        int bc=col/3*3;
        for(int i=br;i<br+3;i++)//the subgrid
        {
            for(int j=bc;j<bc+3;j++)
            {
                if(i!=row&&j!=col)
                {
                    if(board[i][j]==tp)
                        return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int pos)
    {
        if(pos==81)
            return true;
        int row=pos/9;
        int col=pos%9;
        if(board[row][col]=='.')
        {
            for(int i=1;i<10;i++)
            {
                board[row][col]=i+'0';
                if(check(board,pos))
                {
                    if(solve(board,pos+1))//如果失败的话，要把修改的点还原
                        return true;
                }
                board[row][col]='.';
            }
        }
        else
        {
            if(solve(board,pos+1))
                return true;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board,0);
    }
};
