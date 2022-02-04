class Solution {
public:
    int numWays(int n) {
        unordered_map<int, int> res_map;
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        res_map[0] = 1;
        res_map[1] = 1;
        res_map[2] = 2;
        for(int i = 3; i <= n; i++){
            res_map[i] = res_map[i-1] + res_map[i-2];
            res_map[i] %= 1000000007;
        }
        return res_map[n];
    }
};