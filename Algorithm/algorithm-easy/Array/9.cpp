class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> hash_map;
        vector<int> ans;
        int len = nums.size();
        int left =0;
        for(int i=0;i<len;i++){
           left = target - nums[i];
           //查找hash表中出现left
           if(hash_map.find(left) != hash_map.end()){
               ans.push_back(hash_map[left]);
               ans.push_back(i);
                return ans;
           }
           hash_map[nums[i]]=i;
        }
        return ans;
    }
};