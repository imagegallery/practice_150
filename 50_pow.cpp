class Solution {
public:
    double helper(double x, int n){
        if (n == 1)
            return x;
        if(n == 0)
            return 1;
        double a = helper(x, n/2);

        return (n%2) ? (a * x * a) : (a * a);
    }
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        double res = helper(x, abs(n));
        return (n < 0) ? (1 / res) : res;
    }
};