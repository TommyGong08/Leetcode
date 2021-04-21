class Solution {
public:
//实现strStr()
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int pos=haystack.find(needle);
        return pos;
    }
};