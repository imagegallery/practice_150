class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long int temp = x;
        long int num = 0;
        while(temp != 0){
            num = num * 10 +  (temp % 10);
            temp = temp / 10;
        }
        return x == num;
    }
};