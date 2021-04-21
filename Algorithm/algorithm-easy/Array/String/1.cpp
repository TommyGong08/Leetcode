class Solution {
public:
    //反转字符串
    void reverseString(vector<char>& s) {
        int len = s.size();
        char temp;
        if( len == 1) return ;
        for(int i=0;i < len/2 ; i++){
            temp = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = temp;
            }
            return ;
    }
};