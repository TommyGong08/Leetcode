class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        bool flag = false;
        unordered_map<int,bool> mmap;
        for(int i =0 ;i < nums.size(); i++){
            mmap[nums[i]] = true;
        }
        for(int i = 0;i < nums.size(); i ++){
            if(flag == true) break;
            if(mmap.find(target-nums[i]) != mmap.end()){
                ans.push_back(nums[i]);
                ans.push_back(target-nums[i]);
                flag = true;
            }
        }
        return ans;
    }
};