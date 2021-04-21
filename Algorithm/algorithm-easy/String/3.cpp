class Solution {
public:
//字符串中的第一个唯一字符
    int firstUniqChar(string s) {
        int apl[26]={0};
        int len = s.length();
        if(len ==0 ) return -1;
        for(int i=0;i<len;i++){
            apl[s[i]-'a']++;
        }
        int i,flag=0;
        for(i=0;i<len;i++){
            if(apl[s[i]-'a']==1) {
                flag=1;
                break;
            }
        }
        if(flag==0) return -1;
        else return i;
    }
};