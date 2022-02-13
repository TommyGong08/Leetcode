class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //int temp_res = nums[0];
        vector<int> v(nums.size(),0); // 初始化为0
        v[0] = nums[0];
        for(int i =1; i < nums.size();i++){
            int temp_res = v[i-1] + nums[i];
            if(nums[i] >= temp_res){
                v[i] = nums[i];
            }
            else{
                v[i] = temp_res;
            }
        }
        int res = INT_MIN;
        for(int i = 0; i < v.size();i++){
            if(v[i]>res) res = v[i];
        }
        return res;
    }
};