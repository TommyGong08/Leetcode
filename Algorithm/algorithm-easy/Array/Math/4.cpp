class Solution {
public:
    int change(char a)
    {
        switch(a)
        {
            case 'I':return 1;break;
            case 'V':return 5;break;
            case 'X':return 10;break;
            case 'L':return 50;break;
            case 'C':return 100;break;
            case 'D':return 500;break;
            case 'M':return 1000;break;
        }
        return 0;
    }
    int romanToInt(string s) {
        int SUM=0,sum=0;
        int i;
        for(i=0;i<s.length();i++)
        {
            int num=change(s[i]);
            if(change(s[i+1])>num)num=-num;
            SUM+=num;
        }
        return SUM;
    }
};