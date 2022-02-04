class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 记录数组中的重复数字——打表
       unordered_map<int, bool> map;
        for(int num : nums) {
            if(map[num]) return num;
            map[num] = true;
        }
        return -1;
    }
};