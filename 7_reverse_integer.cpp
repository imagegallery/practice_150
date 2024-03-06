class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while(x != 0){
            int temp = x %10;
            if(num > INT_MAX/10 || (num == INT_MAX/10 && temp > 7))
                return 0;
            if(num < INT_MIN/10 || (num == INT_MIN/10 && temp < -8))
                return 0;
            x = x/10;
            num = num *10 + temp;
        }
        return num;
    }
};