/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the". */
//先去掉前置，后置以及中间多余的括号，再翻转整个单词，再翻转每个单词
void fliter(char *s)
{
    int ol=0,ne=0;
    bool first=false;
    while(s[ol]==' ')
    {
        ol++;
    }
    while(s[ol]!='\0')
    {
       if(s[ol]!=' ')
       {
           s[ne]=s[ol];
           ne++;
           ol++;
           first=true;
       }
       else
       {
           if(first)
           {
                s[ne]=s[ol];
                ne++;
                ol++;
                first=false;
           }
           else
                ol++;
       }
    }
    if(ne>=1&&s[ne-1]==' ') s[ne-1]='\0';
    else s[ne]='\0';
}
void reverse(char *s,int begin,int end)
{
    char temp;
    while(begin<end)
    {
        temp=s[begin];
        s[begin]=s[end];
        s[end]=temp;
        begin++;
        end--;
    }
}
void reverseWords(char *s) 
{
    if(s[0]=='\0'||s==NULL)
        return;
    fliter(s);
    if(s[0]=='\0'||s[1]=='\0')
        return;
    int end=0;
    int i=0,j;
    while(s[end]!='\0')
        end++;
    reverse(s,0,end-1);
    while(s[i]!='\0')
    {
        j=i;
        while(s[j]!=' '&&s[j]!='\0')
            j++;
        //printf("%s",s);
        reverse(s,i,j-1);
        if(s[j]=='\0')
            break;
        i=j+1;
    }
}
