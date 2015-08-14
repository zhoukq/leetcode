/* Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6]. */
//思路：每个是等于它左边的所有数的乘积乘以它右边的所有数的乘积，所以可以通过两次循环分别计算这两部分乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> rr(nums.size(),1);
        if(nums.size()<2)
            return rr;
        int left=1,right=1;
        for(int i=0;i<nums.size();i++)
        {
            rr[i]=left;
            left*=nums[i];
            
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            rr[i]*=right;
            right*=nums[i];
        }
        return rr;
           
    }
};
