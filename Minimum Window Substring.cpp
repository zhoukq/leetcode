/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. */
//思路：滑动窗口＋字符hash
//end和start先后向后移动，利用字符hash去匹配
class Solution {
public:
    string minWindow(string s, string t) 
    {
        int start=0,end=0,count=0;
        int min_start=0,min_end=0,min_length=INT_MAX;
        vector<int> need_find(128,0);
        vector<int> has_find(128,0);
        for(int i=0;i<t.length();i++)
        {
            need_find[t[i]]++;
        }
        while(start<s.length()&&end<s.length())
        {
            if(count<t.length())
            {
                while(end<s.length()&&count<t.length())
                {
                    if(need_find[s[end]]>0&&need_find[s[end]]>=++has_find[s[end]])
                        count++;
                    end++;
                }
            }
            while(count==t.length()&&start<s.length())
            {
                if(end-start<min_length)
                {
                    min_start=start;
                    min_end=end;
                    min_length=end-start;
                }
                if(need_find[s[start]]>0&&need_find[s[start]]==has_find[s[start]])
                    count--;
                has_find[s[start]]--;
                start++;
            }
        }
        if(min_start==0&&min_end==0)
            return "";
        else
            return s.substr(min_start,min_length);
    }
};
