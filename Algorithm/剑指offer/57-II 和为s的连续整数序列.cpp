class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        for(int i = 1; i < target; i++){
            vector<int> subAns;
            int sum = i;
            subAns.push_back(i);
            for(int j = i+1; j < target; j++){
                sum += j;
                subAns.push_back(j);
                if(sum == target) {
                    ans.push_back(subAns);
                }
                else if(sum > target){
                    break;
                }
            }
        }
        return ans;
    }
};