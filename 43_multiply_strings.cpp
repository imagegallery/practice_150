class Solution {
public:
    string multiply(string num1, string num2) {
        int sz1 = num1.size();
        int sz2 = num2.size();
        //cout << sz1 << " " << sz2 << endl;
        if(sz1 < sz2)
            multiply(num2, num1);
        if(num1 == "0" || num2 == "0")
            return "0";
        string res(sz1 + sz2, '0');
        for(int i = sz2-1; i >= 0; i--){
            for(int j = sz1-1; j >= 0; j--){
                int prod = (res[i+j+1]-'0') + ((num1[j] - '0') * (num2[i] - '0'));
                res[i+j] = ((res[i+j] - '0') + (prod /10))+'0';
                res[i+j+1] = (prod%10) +'0';
            }
        }
        int i = 0;
        while(res[i] == '0')
            i++;
        //cout << res << endl;
        res=res.substr(i);
        return res;
    }
};