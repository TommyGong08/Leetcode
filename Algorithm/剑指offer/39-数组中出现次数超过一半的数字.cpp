class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int ans = 0 ;
        unordered_map<int,int> mmap;
        for(int i = 0 ;i < nums.size(); i++){
            if(mmap.find(nums[i]) == mmap.end()){
                // 不存在
                mmap[nums[i]] = 1;
            }
            else{
                mmap[nums[i]]++;
                if(mmap[nums[i]] > nums.size() /2) ans = nums[i];
            }
        }
        return ans;
    }
};