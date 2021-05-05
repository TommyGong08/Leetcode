/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 *
 * https://leetcode-cn.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (53.61%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 50K
 * Testcase Example:  '1'
 *
 * 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。
 * 
 * 每个 LED 代表一个 0 或 1，最低位在右侧。
 * 
 * 
 * 
 * （图源：WikiMedia - Binary clock samui moon.jpg ，许可协议：Attribution-ShareAlike 3.0
 * Unported (CC BY-SA 3.0) ）
 * 
 * 例如，上面的二进制手表读取 “3:25”。
 * 
 * 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16",
 * "0:32"]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输出的顺序没有要求。
 * 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
 * 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
 * 超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if(turnedOn == 0){
            ans.push_back("0:00");
            return ans;
        }
        for(int i = 0; i < 12 ;i++){
            for(int j = 0; j < 60 ; j++){
                if(count1(i) + count1(j) == turnedOn){
                    string ss;
                    string min;
                    string h = to_string(i);
                    if(j < 10) min = "0" + to_string(j);
                    else min = to_string(j);
                    ss = h + ":" + min;
                    ans.push_back(ss);
                }
            }
        }
        return ans;
    }
    //计算二进制数中1的位数情况
    int count1(int n){
        int count = 0;
        while(n){
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};
// @lc code=end
/*
遍历时和分 计算二进制数中1是本题的精髓
关于计算二进制数中1的位数情况可以查看这篇博客
https://blog.csdn.net/weixin_43864155/article/details/102076300
*/

