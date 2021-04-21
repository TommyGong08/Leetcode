class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            return intersect(nums2,nums1);
        }
        unordered_map<int,int> hash_map;
        for(int num:nums1){
            hash_map[num]++;
        }
        vector<int> ans;
        for(int num:nums2){
            if(hash_map.count(num)){//nums1中存在num元素
                ans.push_back(num);
                hash_map[num]--;
                if(hash_map[num]==0){
                    hash_map.erase(num);
                }
            }
        }
        return ans;
    }
};