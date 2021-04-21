class Solution {
public:
//验证回文串
    bool isPalindrome(string s) {
        string str;
        for(char i:s){
            if(isalnum(i))//是数字
            {
                str += tolower(i);
            }
        }
        string str_rev(str.rbegin(),str.rend());
        return str == str_rev;
    }
};