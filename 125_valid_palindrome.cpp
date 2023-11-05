class Solution {
public:
    char isLower(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        else if(ch >= 'A' && ch <= 'Z')
            return ch + ('a' - 'A');
        else
            return '-';
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left <= right){
            char l = isLower(s[left]);
            char r = isLower(s[right]);
            //cout << "l is: " << l << " r is: " << r << endl;
            if(l != '-' && r != '-'){
                if(l == r){
                    left ++;
                    right --;
                }else
                    return false;
            }else if(l == '-')
                left++;
            else
                right --;
        }
        return true;
    }
};