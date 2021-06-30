/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (56.89%)
 * Likes:    1376
 * Dislikes: 0
 * Total Accepted:    289.4K
 * Total Submissions: 508.7K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        unordered_map<char,string> phone{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
            };
            string temp_ans;
            backtrack(digits,phone,0,temp_ans,ans);
            return ans;
        }
    void backtrack(const string& digits,const unordered_map<char,string>& phone,int index,string& temp_ans,vector<string>& ans){
        //如果temp_ans的长度等于digits的长度，加入答案中
        if(index == digits.length()){
            ans.push_back(temp_ans);
            return ;
        }
        //如果长度不等，通过当前index查找
        else{
            char digit = digits[index];
            const string& letters = phone.at(digit);
            //对于letters中的每一个元素
            for(const char& letter: letters){
                temp_ans.push_back(letter);
                backtrack(digits,phone,index+1,temp_ans,ans);
                temp_ans.pop_back();
            }
        }
    }
};
// @lc code=end
//如果暴力求解的话你会发现有n个for循环，所以暴力是肯定不能暴力的
//这题我们用回溯算法
