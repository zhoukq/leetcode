/*You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the*/
//思路：动态规划，f(n)=f(n-1)+f(n-1)
class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> temp(n,0);
        temp[0]=1;
        temp[1]=2;
        if(n<=0)
            return 1;
        if(n<3)
            return temp[n-1];
        for(int i=2;i<n;i++)
        {
            temp[i]=temp[i-1]+temp[i-2];
        }
        return temp[n-1];
    }
};
