class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int flag=0;
        sort(nums.begin(),nums.end());
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]==nums[j]){
                //出现两次
                i=j+1;
                j++;
            }
            else{
                flag = 1;
                ans = nums[i];
                break;
            }
        }
        if(flag==1) return ans;
        else return nums[nums.size()-1];
    }
};