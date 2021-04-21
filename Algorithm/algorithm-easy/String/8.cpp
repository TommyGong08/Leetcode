class Solution {
public:
//外观数列
    string countAndSay(int n) {
        //外观数列，递归法
        if(n == 1) return "1";
        string pre = countAndSay(n-1), result = "";
        int count = 1;
        for(int i=0;i<pre.length();i++){
            if(pre[i] == pre[i+1]){
                count ++;
            }
            else{
                result += to_string(count) + pre[i];
                count = 1;
            }
        }
        return result;
    }
};