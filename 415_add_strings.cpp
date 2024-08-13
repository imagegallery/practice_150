class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        //always take num2 as bigger no 
        if(n1 > n2)
            return addStrings(num2, num1);
        string res = "";
        int k = 0, carry = 0;
        int i = n1-1, j = n2-1;
        while(i >= 0 && j >= 0){
            int temp = (num1[i] - '0' + num2[j] - '0' + carry );
            carry = temp / 10;
            res.push_back((temp%10) + '0');
            i--;
            j--;
        }  
        while(j >= 0){
            int temp = ( num2[j] - '0' + carry);
            carry = temp / 10;
            res.push_back((temp%10) + '0');
            j--;
        }
        if(carry){
            res.push_back(carry + '0');
        }
        
        reverse(res.begin(), res.end());
        return res;

    }
};