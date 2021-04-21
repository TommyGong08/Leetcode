class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int flag = 0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j] && i!=j){
                i=j;
            }
            else if(nums[i]==nums[j] && i!=j){
                flag=1;
                break;
            }
            else{
                continue;
            }
        }
        if(flag==1) return true;
        else return false;
    }
};