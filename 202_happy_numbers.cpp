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

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n != 1 && !s.count(n)){
            s.insert(n);
            int sum = 0;
            while(n != 0){
                int a = n%10;
                sum = sum + (a * a);
                n = n / 10;
            }
            n = sum;
            
        }
        return n == 1;
    }
};