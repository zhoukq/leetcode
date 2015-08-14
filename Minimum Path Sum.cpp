/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/
class Solution {
public:
    //f(n,m)=d[n][m]+min(f(n-1,m),f(n,m-1))
    int minPathSum(vector<vector<int>>& grid) 
    {
        int row=grid.size();
        if(row<1)
            return 0;
        int col=grid[0].size();
        if(col<1)   
            return 0;
        int **a=new int*[row];
        for(int i=0;i<row;i++)
            a[i]=new int[col];
        a[0][0]=grid[0][0];
        if(row==1&&col==1)
            return a[0][0];
        else if(row==1)
        {
            int sum=0;
            for(int i=0;i<col;i++)
            {
                sum+=grid[0][i];
            }
            return sum;
        }
        else if(col==1)
        {
            int sum=0;
            for(int i=0;i<row;i++)
            {
                sum+=grid[i][0];
            }
            return sum;
        }
        for(int i=1;i<row;i++)
            a[i][0]=a[i-1][0]+grid[i][0];
        for(int i=1;i<col;i++)
            a[0][i]=a[0][i-1]+grid[0][i];
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                a[i][j]=grid[i][j]+min(a[i-1][j],a[i][j-1]);
            }
        }
        return a[row-1][col-1];
        
    }
};

