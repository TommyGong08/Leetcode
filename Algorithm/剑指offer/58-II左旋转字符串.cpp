class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res = "";
        for(int i =n; i < s.size(); i++){
            res.push_back(s[i]);
        }
        for(int i =0 ; i < n;i++){
            res.push_back(s[i]);
        }
        return res;
    }
};