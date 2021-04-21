class Solution {
public:
//有效的字母异位词
    bool isAnagram(string s, string t) {
        int apl[26]={0};
        int flag=0;
        int len1 = s.length(),len2 = t.length();
        if(len1!= len2) return false;
        for(char i:s){
            apl[i-'a']++;
        }
        for(char i:t){
            apl[i-'a']--;
        }
        for(int i=0;i<26;i++){
            if(apl[i]>0){
                flag =1;
                break;
            }
        }
        if(flag == 1) return false;
        else return true;
    }
};