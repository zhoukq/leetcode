/*You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].*/
//思路：用map存储word里的字符和个数，一个接着一个匹配
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> rr;
        if(words.size()<1||s.size()<1)
            return rr;
        int word_len=words[0].size();
        map<string,int> mstr,counting;
        int i,j;
        for(i=0;i<words.size();i++)
        {
            if(mstr.find(words[i])==mstr.end())
                mstr[words[i]]=1;
            else
                mstr[words[i]]++;
        }
        for(i=0;i<=(int)s.length()-(int)words.size()*word_len;i++)//这里不转int会溢出
        {
            counting.clear();
            for(j=0;j<words.size();j++)
            {
                string wd=s.substr(i+j*word_len,word_len);
                if(mstr.find(wd)!=mstr.end())
                {
                    if(counting.find(wd)==counting.end())
                        counting[wd]=1;
                    else
                        counting[wd]++;
                    if(counting[wd]>mstr[wd])
                        break;
                }
                else
                    break;
            }

            if(j==words.size())
                rr.push_back(i);
        }
        return rr;
        
    }
};
