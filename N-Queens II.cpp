/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
//思路：和之前一样，只需要把在判断结束时次数加一就行
class Solution {
public:
    int tt=0;
    void dfs(int n,int pos,vector<int>& temp)
    {
        if(pos>n)
        {
            //rr.push_back(temp);
            tt++;
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
    int totalNQueens(int n) 
    {
        if(n<1)
            return 0;
        
        vector<int> temp;
        dfs(n,1,temp);
        return tt;
    }
};
