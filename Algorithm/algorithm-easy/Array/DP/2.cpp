//rob
class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int ans=0;
        int f[101];
        f[0]=nums[0];
        f[1]=nums[1];
        f[2] = nums[0]+nums[2];
        ans = max(f[2],f[1]);
        for(int i=3;i<nums.size();i++){
            f[i] = max(f[i-2]+nums[i],f[i-3]+nums[i]);
            ans = max(ans,f[i]);
        }
        return ans; 
    }
};