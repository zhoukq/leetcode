/*The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
//思路：采用回溯和dfs，把结果的位置存在一个vector里，然后再拼成需要的字符串返回。dfs时要判断一个点是否与之前点在同一行，同一列或者同一斜线上，即temp[j]==i||(temp[j]+temp.size()-j==i)||(temp[j]-temp.size()+j==i)
class Solution {
public:
    vector<vector<int>> rr;
    void dfs(int n,int pos,vector<int>& temp)
    {
        if(pos>n)
        {
            rr.push_back(temp);
            return;
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            flag=0;
            for(int j=0;j<temp.size();j++)
            {
                if(temp[j]==i||(temp[j]+temp.size()-j==i)||(temp[j]-temp.size()+j==i))
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                continue;
            else
            {
                temp.push_back(i);
                dfs(n,pos+1,temp);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> srr;
        string a(n,'.');
        if(n<1)
            return srr;
        
        vector<int> temp;
        dfs(n,1,temp);
        for(int i=0;i<rr.size();i++)
        {
            vector<string> tt;
            for(int j=0;j<rr[i].size();j++)
            {
                a[rr[i][j]-1]='Q';
                tt.push_back(a);
                a[rr[i][j]-1]='.';
            }
            srr.push_back(tt);
        }
        return srr;
    }
};
