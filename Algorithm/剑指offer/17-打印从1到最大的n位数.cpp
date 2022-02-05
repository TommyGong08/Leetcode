class Solution {
public:
    vector<int> printNumbers(int n) {
        int max_num = 0;
        vector<int> res;
        for(int i = 0 ; i < n ;i++){
            max_num += 9 * pow(10, i);
        }
        for(int i = 0 ;i < max_num;i++){
            res.push_back(i+1);
        }
        return res;
    }
};