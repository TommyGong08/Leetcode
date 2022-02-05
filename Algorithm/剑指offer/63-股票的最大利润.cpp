class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_price = INT_MAX;
        int temp_res = 0;
        for (int i = 0; i < prices.size(); i++){
            if(prices[i] < min_price){
                min_price = prices[i];
            }
            temp_res = prices[i] - min_price;
            if(temp_res > res) res = temp_res;
        }
        return res;
    }
};