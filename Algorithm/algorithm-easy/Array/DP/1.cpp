//max sub array
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int pre=0;
        for(int i=0;i<nums.size();i++)
        {
            pre = max(pre+nums[i],nums[i]);
            ans = max(pre,ans);
        }
        return ans;
    }
};