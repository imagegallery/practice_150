class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        int a = 1, b = 1, res = 0;
        for(int i = 2; i <= n; i++){
            res = a+b;
            a = b;
            b = res;
        }
        return res;

    }
};