/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1*/
class Solution {
public:
//如果这个数是最大的，则变成最小的
//这个数最高位确定，其他位最大，则最高位换成其他位里比这个最高位大的最少的，然后其他位和原来的高位组成最小的
//递归
void sswap(int& a,int &b)
   {
       int temp=a;
       a=b;
       b=temp;
   }
   void rearrange(vector<int> &rr,int begin)//下标
   {
        int len=rr.size();
        int tp=rr[begin];
        sort(rr.begin()+begin,rr.end());
//        for(int i=0;i<rr.size();i++)
//        {
//            printf("%d ",rr[i]);
//        }
        for(int i=begin;i<rr.size();i++)
        {
            if(rr[i]==tp)
            {
                if((i<rr.size()-1)&&rr[i+1]>rr[i])
                {
                    sswap(rr[begin],rr[i+1]);
                    break;
                }
            }
        }

        sort(rr.begin()+begin+1,rr.end(),less<int>());
   }
   void nextPermutation(vector<int>& nums)
   {
       int flag=0;
       int beg;
       for(int i=nums.size()-1;i>0;i--)
       {
           if(nums[i]>nums[i-1])
           {
              beg=i-1;
              flag=1;
              break;
           }
       }
             //printf("%d ",beg);
       if(!flag)
       {
           reverse(nums.begin(),nums.end());
       }
       else
       {
           rearrange(nums,beg);
       }
   }

};
