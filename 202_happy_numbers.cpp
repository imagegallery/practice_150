class Solution {
public:
    bool isHappy(int n) {
        while(n > 9){
            int num = n;
            int sq = 0;
            while(num != 0){
                int rem = num % 10;
                num = num/10;
                sq += rem*rem;
                //cout << sq << endl;
            }
            n = sq;
        }
        if(n == 1 || n == 7)
            return true;
        else 
            return false;
    }
};