/*Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.*/
//思路：使用优先队列的话时间复杂度会是O(nlgn)，使用单调队列，压入队列时保证数据从后向前时递增的
//这个单调队列的长度是不定的，
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> rr;
        deque<int> temp;
        if(k==0||nums.size()<1)
            return rr;
        for(int i=0;i<nums.size();i++)
        {
            while(!temp.empty()&&temp.front()<=i-k)
                temp.pop_front();
            while(!temp.empty()&&nums[temp.back()]<nums[i])
                temp.pop_back();
            temp.push_back(i);
            if(i>=k-1)
                rr.push_back(nums[temp.front()]);
        }
        return rr;
    }
};
