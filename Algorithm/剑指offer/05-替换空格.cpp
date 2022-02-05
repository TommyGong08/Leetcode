class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        int  k = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else{
                // 
                res.push_back(s[i]); 
            }
        }
        return res;
    }
};