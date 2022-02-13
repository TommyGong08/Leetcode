class Solution {
public:
    char firstUniqChar(string s) {
        char ans = ' ';
        if(s == "") return ' ';
        unordered_map<char,int> map;
        for(int i = 0; i< s.size();i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = 1;
            }
            else{
                map[s[i]]++;
            }
        }
        for(int i = 0; i< s.size();i++){
            if(map[s[i]]==1){
                ans = s[i];
                break;
            }
        }
        return ans;
    }
};