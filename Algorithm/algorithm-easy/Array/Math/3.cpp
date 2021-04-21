class Solution {
public:
    bool isPowerOfThree(int n) {
        bool ans = false;
        if(n<1) return ans;
        while(n%3==0){
            n /= 3;
        }
        return n==1;
    }
};