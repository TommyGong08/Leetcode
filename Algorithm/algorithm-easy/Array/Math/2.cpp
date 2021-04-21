//countPrimes

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0 ;
        vector<bool> sign(n,true);
        for(int i=2;i<n;i++){
            if(sign[i])ans++;
            for(int j=2*i;j<n;j+=i){
                sign[j] = false;
            }
        }
        return ans;
    }
};