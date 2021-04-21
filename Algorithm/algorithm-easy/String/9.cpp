class Solution {
public:
//最长公共前缀
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.size() ==0) return ans;
        char s ;
        int len = strs.size();
        int min_string_len = strs[0].length();
        for(int i=0; i<len ;i++){
            int string_len = strs[i].length();
            if(string_len < min_string_len) min_string_len=string_len; 
        }
        int flag = 0;
        for(int i=0;i<min_string_len;i++){
            s = strs[0][i];
            for(int j=0;j<len;j++){
                if(strs[j][i] != s){
                    flag = -1;
                    break;
                }
            }
            if(flag == -1 ) break;
            else {
                ans += s;
            }
        }
        return ans;
    }
};