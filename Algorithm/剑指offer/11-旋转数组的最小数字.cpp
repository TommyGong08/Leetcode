class Solution {
public:
    int minArray(vector<int>& numbers) {
        int res = numbers[0];
        for(int i = 1; i < numbers.size(); i++){
            if(numbers[i] < numbers[i-1]){
                res = numbers[i];
            }
        }
        return res;
    }
};